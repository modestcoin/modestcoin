// Copyright (c) 2009-2014 The Modestcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?req-dontexist="));
    QVERIFY(!GUIUtil::parseModestcoinURI(uri, &rv));

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?dontexist="));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?amount=0.001"));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?amount=1.001"));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseModestcoinURI("modestcoin://LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseModestcoinURI(uri, &rv));

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseModestcoinURI(uri, &rv));

    uri.setUrl(QString("modestcoin:LEr4HnaeFWYhBmGxCfP2po1NPRueIk8kM2?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseModestcoinURI(uri, &rv));
}
