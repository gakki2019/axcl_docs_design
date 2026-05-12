/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_MOCK_H__
#define __AXCL_RT_MOCK_H__

#include "axcl_rt_stream.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mockApi mock
 */

/**
 * @ingroup mockApi
 * @brief Mock pipeline attributes.
 */
typedef struct {
  uint32_t mode;    /**< Mock running mode. */
  uint32_t param_a; /**< Auxiliary parameter A. */
  uint32_t param_b; /**< Auxiliary parameter B. */
} mockAttr;

/**
 * @ingroup mockApi
 * @brief Initialize the mock runtime.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockInit(void);
/**
 * @ingroup mockApi
 * @brief Deinitialize the mock runtime.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockDeinit(void);

/**
 * @ingroup mockApi
 * @brief Set mock runtime attributes.
 *
 * @param[in] attr        Mock attribute set.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockSetAttr(const mockAttr *attr);
/**
 * @ingroup mockApi
 * @brief Get mock runtime attributes.
 *
 * @param[out] attr       Returned mock attribute set.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockGetAttr(mockAttr *attr);

/**
 * @ingroup mockApi
 * @brief Run mock processing synchronously.
 *
 * @param[in] pInput      Input buffer.
 * @param[in] inSize      Input size in bytes.
 * @param[out] pOutput    Output buffer.
 * @param[in] outSize     Output size in bytes.
 * @param[in] timeoutMs   Timeout in milliseconds.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockProcessSync(const void *pInput, size_t inSize, void *pOutput,
                        size_t outSize, int32_t timeoutMs);
/**
 * @ingroup mockApi
 * @brief Run mock processing asynchronously.
 *
 * @param[in] pInput              Input buffer.
 * @param[in] inSize              Input size in bytes.
 * @param[out] pOutput            Output buffer.
 * @param[in] outSize             Output size in bytes.
 * @param[in] simulateSleepMs     Simulated processing delay in milliseconds.
 * @param[in] stream              Execution stream.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockProcessAsync(const void *pInput, size_t inSize, void *pOutput,
                         size_t outSize, int32_t simulateSleepMs,
                         axclrtStream stream);
/**
 * @ingroup mockApi
 * @brief Submit a mock request that fails intentionally.
 *
 * @param[in] stream        Execution stream.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockProcessAsync_Fail(axclrtStream stream);

/**
 * @ingroup mockApi
 * @brief Send mock channel data.
 *
 * @param[in] chn           Channel identifier.
 * @param[in] data          Source data buffer.
 * @param[in] size          Data size in bytes.
 * @param[in] timeoutMs     Timeout in milliseconds.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockSendData(int32_t chn, const void *data, size_t size,
                     int32_t timeoutMs);
/**
 * @ingroup mockApi
 * @brief Receive mock channel data.
 *
 * @param[in] chn                 Channel identifier.
 * @param[out] buf                Destination buffer.
 * @param[in] bufCapacity         Buffer capacity in bytes.
 * @param[out] actualSize         Received data size in bytes.
 * @param[in] timeoutMs           Timeout in milliseconds.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockRecvData(int32_t chn, void *buf, size_t bufCapacity,
                     size_t *actualSize, int32_t timeoutMs);

/**
 * @ingroup mockApi
 * @brief Start the mock pipeline.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockStart(void);
/**
 * @ingroup mockApi
 * @brief Stop the mock pipeline.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockStop(void);

/* ─── Callback API ────────────────────────────────────────────────── */

/**
 * @ingroup mockApi
 * @brief Callback invoked with a status code and user context.
 */
typedef int32_t (*mockCallbackA_t)(int32_t statusCode, void *userData);
/**
 * @ingroup mockApi
 * @brief Execute mock processing with callback A.
 *
 * @param[in] cb           Callback invoked on completion.
 * @param[in] userData     User context passed to the callback.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockProcessWithCallbackA(mockCallbackA_t cb, void *userData);

/**
 * @ingroup mockApi
 * @brief Callback invoked with a status code.
 */
typedef int32_t (*mockCallbackAEx_t)(int32_t statusCode);
/**
 * @ingroup mockApi
 * @brief Execute mock processing with callback AEx.
 *
 * @param[in] cb           Callback invoked on completion.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockProcessWithCallbackAEx(mockCallbackAEx_t cb);

/**
 * @ingroup mockApi
 * @brief Callback invoked for group and frame notifications.
 */
typedef int32_t (*mockCallbackB_t)(uint32_t grp, uint32_t frameIndex,
                                   void *userData);
/**
 * @ingroup mockApi
 * @brief Register callback B.
 *
 * @param[in] cb           Callback to register.
 * @param[in] userData     User context passed to the callback.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockRegisterCallbackB(mockCallbackB_t cb, void *userData);
/**
 * @ingroup mockApi
 * @brief Unregister callback B.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockUnregisterCallbackB(void);

/**
 * @ingroup mockApi
 * @brief Callback invoked for group and frame notifications without user data.
 */
typedef int32_t (*mockCallbackBEx_t)(uint32_t grp, uint32_t frameIndex);
/**
 * @ingroup mockApi
 * @brief Register callback BEx.
 *
 * @param[in] cb           Callback to register.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockRegisterCallbackBEx(mockCallbackBEx_t cb);
/**
 * @ingroup mockApi
 * @brief Unregister callback BEx.
 *
 * @retval 0 success.
 * @retval others failure.
 */
int32_t mockUnregisterCallbackBEx(void);

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_MOCK_H__ */
