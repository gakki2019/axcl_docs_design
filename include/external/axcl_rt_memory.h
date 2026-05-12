/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_MEMORY_H__
#define __AXCL_RT_MEMORY_H__

#include "axcl_rt_type.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup memApi
 * @brief Allocate device memory.
 *
 * @note
 * - Memory allocated from device is physically continuous memory.
 * - Call @ref axclrtFree to free.
 *
 * @param[out] devPtr        Pointer to allocated device memory.
 * @param[in]  size          Size of memory to allocate.
 * @param[in]  policy        Memory allocation policy, @ref axclrtMemMallocPolicy.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @par Example
 * @code{.c}
 * void *devMem, *hostMem;
 * const size_t size = 1024*1024;
 * axclrtMalloc(&devMem, size, AXCL_MEM_MALLOC_HUGE_FIRST);
 * axclrtMallocHost(&hostMem, size);
 * // memcpy from host to device
 * axclrtMemcpy(devMem, hostMem, size, AXCL_MEMCPY_HOST_TO_DEVICE);
 * axclrtFree(devMem);
 * axclrtFreeHost(hostMem);
 * @endcode
 *
 * @see axclrtFree
 */
AXCL_EXPORT axclError axclrtMalloc(void **devPtr, size_t size, axclrtMemMallocPolicy policy);

/**
 * @ingroup memApi
 * @brief Allocate cached device memory. Call @ref axclrtFree to free memory.
 *
 * @param[out] devPtr        Pointer to allocated cached device memory.
 * @param[in]  size          Size of memory to allocate.
 * @param[in]  policy        Memory allocation policy, @ref axclrtMemMallocPolicy.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtFree
 */
AXCL_EXPORT axclError axclrtMallocCached(void **devPtr, size_t size, axclrtMemMallocPolicy policy);

/**
 * @ingroup memApi
 * @brief Free device memory.
 *
 * @param[in]  devPtr       Device memory allocated by @ref axclrtMalloc.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtMalloc | axclrtMallocCached
 */
AXCL_EXPORT axclError axclrtFree(void *devPtr);

/**
 * @ingroup memApi
 * @brief Flush device memory.
 *
 * @note
 * Only available for cached device memory.
 *
 * @param[in]  devPtr        Device memory.
 * @param[in]  size          Size of memory to flush.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemFlush(void *devPtr, size_t size);

/**
 * @ingroup memApi
 * @brief Invalidate device memory.
 *
 * @note
 * Only available for cached device memory.
 *
 * @param[in]  devPtr        Device memory.
 * @param[in]  size          Size of memory to invalidate.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemInvalidate(void *devPtr, size_t size);

/**
 * @ingroup memApi
 * @brief Allocate host virtual memory.
 *
 * @note
 * @ref axclrtMallocHost is same as malloc function of standard C library, but @ref axclrtMallocHost is recommended.
 *
 * @param[out] hostPtr       Pointer to allocated host virtual memory.
 * @param[in]  size          Size of memory to allocate.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtFreeHost
 */
AXCL_EXPORT axclError axclrtMallocHost(void **hostPtr, size_t size);

/**
 * @ingroup memApi
 * @brief Free host virtual memory.
 *
 * @param[in]  hostPtr       Host memory.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtMallocHost
 */
AXCL_EXPORT axclError axclrtFreeHost(void *hostPtr);

/**
 * @ingroup memApi
 * @brief Set device memory to the specified value.
 *
 * @note
 * @ref axclrtMemset only support device memory.
 *
 * @param[in]  devPtr        Device memory.
 * @param[in]  value         Value to set.
 * @param[in]  count         Number of bytes to set.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemset(void *devPtr, uint8_t value, size_t count);

/**
 * @ingroup memApi
 * @brief Copy memory.
 *
 * @param[in]  dstPtr        Destination memory.
 * @param[in]  srcPtr        Source memory.
 * @param[in]  count         Number of bytes to copy.
 * @param[in]  kind          Memory copy kind of @ref axclrtMemcpyKind.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 *
 * @see axclrtMalloc
 */
AXCL_EXPORT axclError axclrtMemcpy(void *dstPtr, const void *srcPtr, size_t count, axclrtMemcpyKind kind);

/**
 * @ingroup memApi
 * @brief Compare device memories.
 *
 * @param[in]  devPtr1       First device memory.
 * @param[in]  devPtr2       Second device memory.
 * @param[in]  count         Number of bytes to compare.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemcmp(const void *devPtr1, const void *devPtr2, size_t count);

/**
 * @ingroup memApi
 * @brief Set device memory asynchronously.
 *
 * @param[in]  devPtr        Pointer to device memory to set.
 * @param[in]  value         Value to set.
 * @param[in]  count         Number of bytes to set.
 * @param[in]  stream        stream created by @ref axclrtCreateStream.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemsetAsync(void *devPtr, uint8_t value, size_t count, axclrtStream stream);

/**
 * @ingroup memApi
 * @brief Copy memory asynchronously.
 *
 * @param[in]  dstPtr        Destination memory.
 * @param[in]  srcPtr        Source memory.
 * @param[in]  count         Number of bytes to copy.
 * @param[in]  kind          Memory copy kind of @ref axclrtMemcpyKind.
 * @param[in]  stream        stream created by @ref axclrtCreateStream.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemcpyAsync(void *dstPtr, const void *srcPtr, size_t count, axclrtMemcpyKind kind, axclrtStream stream);

/**
 * @ingroup memApi
 * @brief Compare device memories asynchronously.
 *
 * @param[in]  devPtr1       First device memory.
 * @param[in]  devPtr2       Second device memory.
 * @param[in]  count         Number of bytes to compare.
 * @param[in]  stream        stream created by @ref axclrtCreateStream.
 *
 * @retval AXCL_SUCC success.
 * @retval others failure.
 */
AXCL_EXPORT axclError axclrtMemcmpAsync(const void *devPtr1, const void *devPtr2, size_t count, axclrtStream stream);

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_RT_MEMORY_H__ */