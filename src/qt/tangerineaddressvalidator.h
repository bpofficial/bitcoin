// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TANGERINE_QT_TANGERINEADDRESSVALIDATOR_H
#define TANGERINE_QT_TANGERINEADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TangerineAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TangerineAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Tangerine address widget validator, checks for a valid tangerine address.
 */
class TangerineAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TangerineAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // TANGERINE_QT_TANGERINEADDRESSVALIDATOR_H
