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

#include <stddef.h>
#include <stdint.h>
#include "axcl_rt_stream.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t mode;
    uint32_t param_a;
    uint32_t param_b;
} mockAttr;

int32_t mockInit(void);
int32_t mockDeinit(void);

int32_t mockSetAttr(const mockAttr* attr);
int32_t mockGetAttr(mockAttr* attr);

int32_t mockProcessSync(const void* pInput, size_t inSize, void* pOutput, size_t outSize, int32_t timeoutMs);
int32_t mockProcessAsync(const void* pInput, size_t inSize, void* pOutput, size_t outSize, int32_t simulateSleepMs, axclrtStream stream);
int32_t mockProcessAsync_Fail(axclrtStream stream);

int32_t mockSendData(int32_t chn, const void* data, size_t size, int32_t timeoutMs);
int32_t mockRecvData(int32_t chn, void* buf, size_t bufCapacity, size_t* actualSize, int32_t timeoutMs);

int32_t mockStart(void);
int32_t mockStop(void);

/* ─── Callback API ────────────────────────────────────────────────── */

typedef int32_t (*mockCallbackA_t)(int32_t statusCode, void* userData);
int32_t mockProcessWithCallbackA(mockCallbackA_t cb, void* userData);

typedef int32_t (*mockCallbackAEx_t)(int32_t statusCode);
int32_t mockProcessWithCallbackAEx(mockCallbackAEx_t cb);

typedef int32_t (*mockCallbackB_t)(uint32_t grp, uint32_t frameIndex, void* userData);
int32_t mockRegisterCallbackB(mockCallbackB_t cb, void* userData);
int32_t mockUnregisterCallbackB(void);

typedef int32_t (*mockCallbackBEx_t)(uint32_t grp, uint32_t frameIndex);
int32_t mockRegisterCallbackBEx(mockCallbackBEx_t cb);
int32_t mockUnregisterCallbackBEx(void);

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_MOCK_H__ */
