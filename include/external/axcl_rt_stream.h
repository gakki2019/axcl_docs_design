/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_STREAM_H__
#define __AXCL_RT_STREAM_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup streamApi
 * @brief Create a stream.
 *
 * @param[out] stream      pointer to created stream
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtCreateStream(axclrtStream *stream);

/**
 * @ingroup streamApi
 * @brief Destroy a stream.
 *
 * @param[in] stream      stream created by @ref axclrtCreateStream to destroy.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtDestroyStream(axclrtStream stream);

/**
 * @ingroup streamApi
 * @brief Destroy a stream forcefully.
 *
 * @param[in] stream      stream created by @ref axclrtCreateStream to destroy.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtDestroyStreamForce(axclrtStream stream);

/**
 * @ingroup streamApi
 * @brief Synchronize a stream.
 *
 * @param[in] stream      stream created by @ref axclrtCreateStream to synchronize.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSynchronizeStream(axclrtStream stream);

/**
 * @ingroup streamApi
 * @brief Synchronize a stream with timeout.
 *
 * @param[in] stream      stream created by @ref axclrtCreateStream to synchronize.
 * @param[in] timeout     timeout in milliseconds, -1 for no timeout.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSynchronizeStreamWithTimeout(axclrtStream stream, int32_t timeout);

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_STREAM_H__ */