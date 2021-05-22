#!/usr/bin/env bash
# Copyright (c) 2016-2020 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

TANGERINED=${TANGERINED:-$BINDIR/tangerined}
TANGERINECLI=${TANGERINECLI:-$BINDIR/tangerine-cli}
TANGERINETX=${TANGERINETX:-$BINDIR/tangerine-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/tangerine-wallet}
TANGERINEUTIL=${TANGERINEQT:-$BINDIR/tangerine-util}
TANGERINEQT=${TANGERINEQT:-$BINDIR/qt/tangerine-qt}

[ ! -x $TANGERINED ] && echo "$TANGERINED not found or not executable." && exit 1

# Don't allow man pages to be generated for binaries built from a dirty tree
DIRTY=""
for cmd in $TANGERINED $TANGERINECLI $TANGERINETX $WALLET_TOOL $TANGERINEUTIL $TANGERINEQT; do
  VERSION_OUTPUT=$($cmd --version)
  if [[ $VERSION_OUTPUT == *"dirty"* ]]; then
    DIRTY="${DIRTY}${cmd}\n"
  fi
done
if [ -n "$DIRTY" ]
then
  echo -e "WARNING: the following binaries were built from a dirty tree:\n"
  echo -e $DIRTY
  echo "man pages generated from dirty binaries should NOT be committed."
  echo "To properly generate man pages, please commit your changes to the above binaries, rebuild them, then run this script again."
fi

# The autodetected version git tag can screw up manpage output a little bit
read -r -a TNGVER <<< "$($TANGERINECLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for tangerined if --version-string is not set,
# but has different outcomes for tangerine-qt and tangerine-cli.
echo "[COPYRIGHT]" > footer.h2m
$TANGERINED --version | sed -n '1!p' >> footer.h2m

for cmd in $TANGERINED $TANGERINECLI $TANGERINETX $WALLET_TOOL $TANGERINEUTIL $TANGERINEQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${TNGVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${TNGVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
