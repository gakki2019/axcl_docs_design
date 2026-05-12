/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_DEVICE_H__
#define __AXCL_RT_DEVICE_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup deviceApi
 * @brief Activate device.
 *
 * @note
 * - @ref axclrtSetDevice can be called multiple times, correspondingly call @ref axclrtResetDevice to deactivate.
 * - When the 1st time to activate the device, the system will create a default context and a default stream.
 * - Invoke @ref axclrtSetDevice to activate the same device in different threads, those threads use the same default context and default stream.
 *
 * @param[in] deviceId      device id, [0 - (device count - 1)]
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtResetDevice | axclrtCreateContext
 */
AXCL_EXPORT axclError axclrtSetDevice(int32_t deviceId);

/**
 * @ingroup deviceApi
 * @brief Deactivate device.
 *
 * @note
 * - Before deactive, all contexts and streams will wait for finished synchronization.
 * - All explicit created contexts and streams should be destroyed before deactive, that means:
 *    @ref axclrtDestroyStream -> @ref axclrtDestroyContext -> @ref axclrtResetDevice
 *
 * @param[in] deviceId      device id
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtResetDevice(int32_t deviceId);

/**
 * @ingroup deviceApi
 * @brief Get device id of current calling thread.
 *
 * @param[out] deviceId      device id
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtGetDevice(int32_t *deviceId);

/**
 * @ingroup deviceApi
 * @brief Get the number of devices.
 *
 * @param[out] count       number of devices
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtGetDeviceCount(uint32_t *count);

/**
 * @ingroup deviceApi
 * @brief Get the UID of a device.
 *
 * @param[in] deviceId      device id
 * @param[out] uid          UID of the device
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtDeviceGetUid(int32_t deviceId, uint64_t *uid);

/**
 * @ingroup deviceApi
 * @brief Block the current thread until the device bound to the current context has completed.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSynchronizeDevice();

/**
 * @ingroup deviceApi
 * @brief Block the current thread until the device which is bound to the current context has completed in timeout.
 *
 * @param[in] timeout       timeout in milliseconds, -1 for no timeout.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtSynchronizeDeviceWithTimeout(int32_t timeout);


#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_DEVICE_H__ */