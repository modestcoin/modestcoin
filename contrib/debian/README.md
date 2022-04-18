
Debian
====================
This directory contains files used to package modestcoind/modestcoin-qt
for Debian-based Linux systems. If you compile modestcoind/modestcoin-qt yourself, there are some useful files here.

## modestcoin: URI support ##


modestcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install modestcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your modestcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/modestcoin128.png` to `/usr/share/pixmaps`

modestcoin-qt.protocol (KDE)

