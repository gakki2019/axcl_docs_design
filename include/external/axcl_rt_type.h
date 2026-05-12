/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_TYPE_H__
#define __AXCL_RT_TYPE_H__

#include "axcl_base.h"
#include "axcl_error.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

typedef void   *axclrtContext;
typedef void   *axclrtStream;
typedef void   *axclrtEvent;

#define INVALID_AXCL_CONTEXT    ((axclrtContext)0)
#define INVALID_AXCL_STREAM     ((axclrtStream )0)
#define INVALID_AXCL_EVENT      ((axclrtEvent  )0)

/**
 * @brief Mem malloc policy enum.
 */
typedef enum axclrtMemMallocPolicy {
    AXCL_MEM_MALLOC_HUGE_FIRST      = 0,  /*!< Huge first */
    AXCL_MEM_MALLOC_HUGE_ONLY       = 1,  /*!< Huge only */
    AXCL_MEM_MALLOC_NORMAL_ONLY     = 2,  /*!< Normal only */
    AXCL_MEM_MALLOC_SIZE_ALIGN      = 3   /*!< Size aligned */
} axclrtMemMallocPolicy;

/**
 * @brief Memcpy kind enum.
 */
typedef enum axclrtMemcpyKind {
    AXCL_MEMCPY_HOST_TO_HOST         = 0,   /*!< Host virtual memory to host virtual memory */
    AXCL_MEMCPY_HOST_TO_DEVICE       = 1,   /*!< Host virtual memory to device memory */
    AXCL_MEMCPY_DEVICE_TO_HOST       = 2,   /*!< Device memory to host virtual memory */
    AXCL_MEMCPY_DEVICE_TO_DEVICE     = 3,   /*!< Device memory to device memory */
    AXCL_MEMCPY_HOST_PHY_TO_DEVICE   = 4,   /*!< Host physical memory to device memory */
    AXCL_MEMCPY_DEVICE_TO_HOST_PHY   = 5    /*!< Device memory to host physical memory */
} axclrtMemcpyKind;

/**
 * @brief File transfer policy enum.
 */
typedef enum axclrtFileTransferPolicy {
    AXCL_FILE_TRANSFER_FROM_HOST_TO_DEVICE   = 0,  /*!< Transfer file from host to device */
    AXCL_FILE_TRANSFER_FROM_DEVICE_TO_HOST   = 1,  /*!< Transfer file from device to host */
    AXCL_FILE_TRANSFER_FROM_DEVICE_TO_DEVICE = 2,  /*!< Transfer file from device to device */
    AXCL_FILE_TRANSFER_REMOVE_DEVICE_FILE    = 3   /*!< Remove file from device */
} axclrtFileTransferPolicy;

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_TYPE_H__ */
