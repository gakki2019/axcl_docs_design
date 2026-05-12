/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_BASE_H__
#define __AXCL_BASE_H__

#include <stddef.h>
#include <stdint.h>

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup baseApi base
 */

#if defined(__GNUC__) || defined(__clang__)
    #define AXCL_EXPORT __attribute((visibility("default")))
#elif defined(_WIN32)
    #if defined(AXCL_EXPORTS)
        #define AXCL_EXPORT __declspec(dllexport)
    #else
        #define AXCL_EXPORT __declspec(dllimport)
    #endif
#else
    #define AXCL_EXPORT
    #pragma message("AXCL_EXPORT is not defined")
#endif

/**
 * @ingroup baseApi
 * @brief Timeout value used to wait indefinitely.
 */
#define NO_TIMEOUT (-1)

#ifndef AXCL_BUILD_FOR_DEVICE
    // host
    #define AX_ID_AXCL          (0x30)
#else
    // device
    #define AX_ID_AXCL          (0x31)
#endif

// axcl modules start from 0x50
#define AXCL_COMM               (0x50)
#define AXCL_PROTOCOL           (0x51)
#define AXCL_RUNTIME            (0x52)
#define AXCL_LITE               (0x53)
#define AXCL_NATIVE             (0x54)
#define AXCL_DAEMON             (0x55)
#define AXCL_WORKER             (0x56)
#define AXCL_CTRL               (0x57)

// keep native module same as AX_MOD_ID_E
#define AXCL_SYS                (0x0B)
#define AXCL_VDEC               (0x08)
#define AXCL_VENC               (0x07)
#define AXCL_IVPS               (0x0D)
#define AXCL_IVE                (0x15)
#define AXCL_ENGINE             (0x1D)

/**
 * @ingroup baseApi
 * @brief Public AXCL error code type.
 */
typedef int32_t axclError;

/**
 * @ingroup baseApi
 * @brief Common AXCL status and generic error identifiers.
 */
typedef enum {
    AXCL_SUCC                   = 0x00,
    AXCL_FAIL                   = 0x01,
    AXCL_ERR_UNKNOWN            = AXCL_FAIL,
    AXCL_ERR_NULL_POINTER       = 0x02,
    AXCL_ERR_ILLEGAL_PARAM      = 0x03,
    AXCL_ERR_UNSUPPORT          = 0x04,
    AXCL_ERR_TIMEOUT            = 0x05,
    AXCL_ERR_BUSY               = 0x06,
    AXCL_ERR_NO_MEMORY          = 0x07,
    AXCL_ERR_ENCODE             = 0x08,
    AXCL_ERR_DECODE             = 0x09,
    AXCL_ERR_UNEXPECT_RESPONSE  = 0x0A,

    AXCL_ERR_MODULE_BASE        = 0x20,
    AXCL_ERR_BUTT               = 0x7F
} AXCL_ERROR_E;

/*
* -------------------------------------------------------------------------|
* |1|      FIXED     |    AX_ID_AXCL   |  SUB_MODULE_ID  |     ERR_ID      |
* |------------------------------------------------------------------------|
* |1|<--- 7bits  --->|<---- 8bits ---->|<---- 8bits ---->|<---- 8bits ---->|
*/
/**
 * @ingroup baseApi
 * @brief Compose a module-specific AXCL error code.
 */
#define AXCL_DEF_ERR(sub, errid) \
    ((axclError)((0x80000000L) | ((AX_ID_AXCL) << 16 ) | ((sub) << 8) | (errid)))

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_BASE_H__ */
