// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TANGERINE_SCRIPT_TANGERINECONSENSUS_H
#define TANGERINE_SCRIPT_TANGERINECONSENSUS_H

#include <stdint.h>

#if defined(BUILD_TANGERINE_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/tangerine-config.h>
  #if defined(_WIN32)
    #if defined(HAVE_DLLEXPORT_ATTRIBUTE)
      #define EXPORT_SYMBOL __declspec(dllexport)
    #else
      #define EXPORT_SYMBOL
    #endif
  #elif defined(HAVE_DEFAULT_VISIBILITY_ATTRIBUTE)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBTANGERINECONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define TANGERINECONSENSUS_API_VER 1

typedef enum tangerineconsensus_error_t
{
    tangerineconsensus_ERR_OK = 0,
    tangerineconsensus_ERR_TX_INDEX,
    tangerineconsensus_ERR_TX_SIZE_MISMATCH,
    tangerineconsensus_ERR_TX_DESERIALIZE,
    tangerineconsensus_ERR_AMOUNT_REQUIRED,
    tangerineconsensus_ERR_INVALID_FLAGS,
} tangerineconsensus_error;

/** Script verification flags */
enum
{
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    tangerineconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = tangerineconsensus_SCRIPT_FLAGS_VERIFY_P2SH | tangerineconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               tangerineconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | tangerineconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               tangerineconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | tangerineconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int tangerineconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, tangerineconsensus_error* err);

EXPORT_SYMBOL int tangerineconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, tangerineconsensus_error* err);

EXPORT_SYMBOL unsigned int tangerineconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // TANGERINE_SCRIPT_TANGERINECONSENSUS_H
