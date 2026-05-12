/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_H__
#define __AXCL_H__

#include "axcl_rt.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup axclApi system
 */

/**
 * @defgroup deviceApi device
 */

/**
 * @defgroup contextApi context
 */

/**
 * @defgroup streamApi stream
 */

/**
 * @defgroup memApi memory
 */

/**
 * @defgroup controlApi control
 */

/**
 * @defgroup engineApi engine
 */

/**
 * @defgroup eventApi event
 */

/**
 * @ingroup axclApi
 * @brief Initialize axcl runtime.
 *
 * @param[in] json        json config of the following:
 *  - json config file path.
 *  - json config content string.
 *  - NULL, use default config.
 *
 * @note
 * - @ref axclInit should be callled before any other APIs.
 * - @ref axclInit can be called multiple times, but only the first call of config parameter will be used.
 * - @ref axclFinalize should be called in pair with @ref axclInit, for example:
 *        axclInit(NULL);
 *        axclInit(NULL);
 *        axclFinalize();
 *        axclFinalize();
 * - Usually @ref axclInit and @ref axclFinalize are called in the main function of the application.
 *
 * @par Example
 * @code{.c}
 * int main(int argc, char *argv[]) {
 *      axclInit(NULL);
 *
 *      // TODO:
 *
 *      axclFinalize();
 *      return 0;
 * }
 * @endcode
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclInit(const char *json);

/**
 * @ingroup axclApi
 * @brief Finalize axcl runtime.
 *
 * @note
 * - @ref axclFinalize must be called explicitly before quit, otherwise causes terminated abort.
 * - Do not call @ref axclFinalize in destructor.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclInit
 */
AXCL_EXPORT axclError axclFinalize();

/**
 * @ingroup axclApi
 * @brief Set axcl log level.
 *
 * @param[in] lv        log level
 *                      0: trace
 *                      1: debug
 *                      2: info
 *                      3: warning
 *                      4: error
 *                      5: critical
 *                      6: off
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclSetLogLevel(int32_t lv);


/**
 * @ingroup axclApi
 * @brief Get axcl log level.
 *
 * @param[out] lv        log level
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclGetLogLevel(int32_t *lv);

/**
 * @ingroup axclApi
 * @brief Record an application log in the following format.
 *        [date time][tid][level][APP][function][file][line]: formatted message
 *        Example:
 *          axclAppLog(5, __func__, NULL, __LINE__, "json: %s, device: %d", json, device);
 *          log:
 *          [2024-11-12 14:24:22.380][1330][C][APP][main][53]: json: ./axcl.json, device: 129
 *
 * @param[in] lv        log level, refer to @ref axclSetLogLevel.
 * @param[in] func      function name; if set to NULL, the function name will not be printed.
 * @param[in] file      file name; if set to NULL, the file name will not be printed.
 * @param[in] line      line number
 * @param[in] fmt       format string for the log message, max. length is 1024.
 *
 * @see axclSetLogLevel
 */
AXCL_EXPORT void axclAppLog(int32_t lv, const char *func, const char *file, uint32_t line, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

// clang-format on

#endif /* __AXCL_H__ */