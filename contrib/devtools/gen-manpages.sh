#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

MODESTCOIND=${MODESTCOIND:-$SRCDIR/modestcoind}
MODESTCOINCLI=${MODESTCOINCLI:-$SRCDIR/modestcoin-cli}
MODESTCOINTX=${MODESTCOINTX:-$SRCDIR/modestcoin-tx}
MODESTCOINQT=${MODESTCOINQT:-$SRCDIR/qt/modestcoin-qt}

[ ! -x $MODESTCOIND ] && echo "$MODESTCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($MODESTCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for modestcoind if --version-string is not set,
# but has different outcomes for modestcoin-qt and modestcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$MODESTCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $MODESTCOIND $MODESTCOINCLI $MODESTCOINTX $MODESTCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
