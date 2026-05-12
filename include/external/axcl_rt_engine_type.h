/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_ENGINE_TYPE_H__
#define __AXCL_RT_ENGINE_TYPE_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup engineApi
 * @brief Maximum number of dimensions supported by an engine tensor.
 */
#define AXCLRT_ENGINE_MAX_DIM_CNT 32

/**
 * @ingroup engineApi
 * @brief Opaque handle used to query engine input and output metadata.
 */
typedef void* axclrtEngineIOInfo;
/**
 * @ingroup engineApi
 * @brief Opaque handle used to bind engine input and output buffers.
 */
typedef void* axclrtEngineIO;
/**
 * @ingroup engineApi
 * @brief Bitmask describing the engine core affinity set.
 */
typedef uint32_t axclrtEngineSet;

/**
 * @ingroup engineApi
 * @brief Model core-count classification.
 */
typedef enum axclrtEngineModelKind {
    AXCL_MODEL_TYPE_1CORE = 0,
    AXCL_MODEL_TYPE_2CORE = 1,
    AXCL_MODEL_TYPE_3CORE = 2,
} axclrtEngineModelKind;

/**
 * @ingroup engineApi
 * @brief VNPU scheduling mode.
 */
typedef enum axclrtEngineVNpuKind {
    AXCL_VNPU_DISABLE = 0,
    AXCL_VNPU_ENABLE = 1,
    AXCL_VNPU_BIG_LITTLE = 2,
    AXCL_VNPU_LITTLE_BIG = 3,
} axclrtEngineVNpuKind;

/**
 * @ingroup engineApi
 * @brief Tensor data type definition.
 */
typedef enum axclrtEngineDataType {
    AXCL_DATA_TYPE_NONE = 0,
    AXCL_DATA_TYPE_INT4 = 1,
    AXCL_DATA_TYPE_UINT4 = 2,
    AXCL_DATA_TYPE_INT8 = 3,
    AXCL_DATA_TYPE_UINT8 = 4,
    AXCL_DATA_TYPE_INT16 = 5,
    AXCL_DATA_TYPE_UINT16 = 6,
    AXCL_DATA_TYPE_INT32 = 7,
    AXCL_DATA_TYPE_UINT32 = 8,
    AXCL_DATA_TYPE_INT64 = 9,
    AXCL_DATA_TYPE_UINT64 = 10,
    AXCL_DATA_TYPE_FP4 = 11,
    AXCL_DATA_TYPE_FP8 = 12,
    AXCL_DATA_TYPE_FP16 = 13,
    AXCL_DATA_TYPE_BF16 = 14,
    AXCL_DATA_TYPE_FP32 = 15,
    AXCL_DATA_TYPE_FP64 = 16,
} axclrtEngineDataType;

/**
 * @ingroup engineApi
 * @brief Tensor layout definition.
 */
typedef enum axclrtEngineDataLayout {
    AXCL_DATA_LAYOUT_NONE = 0,
    AXCL_DATA_LAYOUT_NHWC = 1,
    AXCL_DATA_LAYOUT_NCHW = 2,
} axclrtEngineDataLayout;

/**
 * @ingroup engineApi
 * @brief Tensor dimensions returned by engine shape query APIs.
 */
typedef struct axclrtEngineIODims {
    int32_t dimCount;                           /**< Number of valid dimensions in the shape. */
    int32_t dims[AXCLRT_ENGINE_MAX_DIM_CNT];    /**< Dimension values in logical tensor order. */
} axclrtEngineIODims;

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_ENGINE_TYPE_H__ */