/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_EVENT_H__
#define __AXCL_RT_EVENT_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup eventApi
 * @brief Create an event.
 *
 * @param[out] event        pointer to created event
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtCreateEvent(axclrtEvent *event);

/**
 * @ingroup eventApi
 * @brief Destroy an event.
 *
 * @param[in] event      event created by @ref axclrtCreateEvent to destroy.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtDestroyEvent(axclrtEvent event);

/**
 * @ingroup eventApi
 * @brief Record an event on a stream.
 *
 * @param[in] event      event created by @ref axclrtCreateEvent to record.
 * @param[in] stream     stream created by @ref axclrtCreateStream to record the event.
 */
AXCL_EXPORT axclError axclrtRecordEvent(axclrtEvent event, axclrtStream stream);

/**
 * @ingroup eventApi
 * @brief Wait for an event on a stream.
 *
 * @param[in] stream     stream created by @ref axclrtCreateStream to wait for the event.
 * @param[in] event      event created by @ref axclrtCreateEvent to wait for.
 */
AXCL_EXPORT axclError axclrtStreamWaitEvent(axclrtStream stream, axclrtEvent event);

/**
 * @ingroup eventApi
 * @brief Wait for an event on a stream with timeout.
 *
 * @param[in] stream     stream created by @ref axclrtCreateStream to wait for the event.
 * @param[in] event      event created by @ref axclrtCreateEvent to wait for.
 * @param[in] timeout    timeout in milliseconds, -1 for no timeout.
 */
AXCL_EXPORT axclError axclrtStreamWaitEventWithTimeout(axclrtStream stream, axclrtEvent event, int32_t timeout);

/**
 * @ingroup eventApi
 * @brief Block host until the event is signaled (recorded).
 *
 * @param[in] event      event created by @ref axclrtCreateEvent to wait for.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSynchronizeEvent(axclrtEvent event);

/**
 * @ingroup eventApi
 * @brief Block host until the event is signaled (recorded) with timeout.
 *
 * @param[in] event      event created by @ref axclrtCreateEvent to wait for.
 * @param[in] timeout    timeout in milliseconds, -1 for no timeout.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSynchronizeEventWithTimeout(axclrtEvent event, int32_t timeout);

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_EVENT_H__ */
