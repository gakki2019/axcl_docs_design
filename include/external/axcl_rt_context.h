/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_CONTEXT_H__
#define __AXCL_RT_CONTEXT_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup contextApi
 * @brief Create a context on specified device and bind to calling thread.
 *
 * @note
 * - If don't call the @ref axclrtCreateContext API to explicitly create the context,
 * the system will use the default context, which is implicitly created when the @ref axclrtSetDevice API is called.
 * - If multiple contexts are created in calling thread, only the latest created
 * context will be used.
 * - @ref axclrtDestroyContext must be called explicitly to destroy the created context.
 *
 * @param[out] context      pointer to created context
 * @param[in] deviceId      device id
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @par Example
 * @code{.c}
 * // create a context and bind to device_id
 * void working_thread(int device_id) {
 *      // create a context and bind to calling thread
 *      axclrtContext context;
 *      axclrtCreateContext(&context, device_id);
 *
 *      // TODO: working body
 *
 *      // destroy the context before thread quit.
 *      axclrtDestroyContext(context);
 * }
 * @endcode
 *
 * @see axclrtDestroyContext | axclrtSetDevice
 */
AXCL_EXPORT axclError axclrtCreateContext(axclrtContext *context, int32_t deviceId);

/**
 * @ingroup contextApi
 * @brief Destroy the context explicitly created by @ref axclrtCreateContext.
 *
 * @note
 * - @ref axclrtDestroyContext cannot destroy the default context which is created by @ref axclrtSetDevice.
 *
 * @param[in] context       context created by @ref axclrtCreateContext.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtCreateContext | axclrtSetDevice
 */
AXCL_EXPORT axclError axclrtDestroyContext(axclrtContext context);

/**
 * @ingroup contextApi
 * @brief Bind the specified context to current calling thread.
 *
 * @param[in] context      context.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSetCurrentContext(axclrtContext context);

/**
 * @ingroup contextApi
 * @brief Get context of current calling thread.
 *
 * @param[out] context      pointer to context.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtGetCurrentContext(axclrtContext *context);

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_CONTEXT_H__ */