// Copyright (c) 2011-2014 The Modestcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MODESTCOIN_QT_MODESTCOINADDRESSVALIDATOR_H
#define MODESTCOIN_QT_MODESTCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ModestcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ModestcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Modestcoin address widget validator, checks for a valid modestcoin address.
 */
class ModestcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ModestcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // MODESTCOIN_QT_MODESTCOINADDRESSVALIDATOR_H
