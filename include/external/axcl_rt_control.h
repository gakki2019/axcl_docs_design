/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_CONTROL_H__
#define __AXCL_RT_CONTROL_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup controlApi
 * @brief Execute a shell command.
 *
 * @param[in] cmd       The command to execute.
 * @param[in] args      The arguments to the command.
 * @param[in] argc      The number of arguments.
 * @param[out] output   The output of the command.
 * @param[in] timeout   The timeout in milliseconds.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtControlExecuteShellCmd(const char *cmd, const char *const args[], size_t argc, const char **output, int32_t timeout);

#ifdef __cplusplus
}
#endif
// clang-format on

#endif  // __AXCL_RT_CONTROL_H__