// Copyright (c) 2009-2016 The Modestcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MODESTCOIN_QT_TEST_COMPATTESTS_H
#define MODESTCOIN_QT_TEST_COMPATTESTS_H

#include <QObject>
#include <QTest>

class CompatTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void bswapTests();
};

#endif // MODESTCOIN_QT_TEST_COMPATTESTS_H
