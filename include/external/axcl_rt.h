/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_H__
#define __AXCL_RT_H__

#include "axcl_rt_context.h"
#include "axcl_rt_device.h"
#include "axcl_rt_engine.h"
#include "axcl_rt_event.h"
#include "axcl_rt_memory.h"
#include "axcl_rt_stream.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup axclApi
 * @brief Get axcl version.
 *
 * @param[out] major    major version.
 * @param[out] minor    minor version.
 * @param[out] patch    patch version.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtGetVersion(int32_t *major, int32_t *minor, int32_t *patch);

/**
 * @ingroup axclApi
 * @brief Get axcl version string.
 *
 * @return Version string.
 */
AXCL_EXPORT const char *axclrtGetVersionStr();

/**
 * @ingroup axclApi
 * @brief Get chip name.
 *
 * @return Chip name string.
 */
AXCL_EXPORT const char *axclrtGetSocName();

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_H__ */