/**************************************************************************************************
 *
 * Copyright (c) 2019-2026 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_ERROR_H__
#define __AXCL_ERROR_H__

#include "axcl_base.h"

// clang-format off
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************************
 * comm error
****************************************************************************************************/
#define AXCL_DEF_COMM_ERR(errid)                AXCL_DEF_ERR(AXCL_COMM, (errid))
                                                                                                        /*           HOST           |         DEVICE         */
/* generic: 0x00 ~ 0x1F */
#define AXCL_ERR_COMM_NULL_POINTER              AXCL_DEF_COMM_ERR(AXCL_ERR_NULL_POINTER)                /* -2144317438, 0x80305002;  -2144251902, 0x80315002 */
#define AXCL_ERR_COMM_ILLEGAL_PARAM             AXCL_DEF_COMM_ERR(AXCL_ERR_ILLEGAL_PARAM)               /* -2144317437, 0x80305003;  -2144251901, 0x80315003 */
#define AXCL_ERR_COMM_UNSUPPORT                 AXCL_DEF_COMM_ERR(AXCL_ERR_UNSUPPORT)                   /* -2144317436, 0x80305004;  -2144251900, 0x80315004 */
#define AXCL_ERR_COMM_TIMEOUT                   AXCL_DEF_COMM_ERR(AXCL_ERR_TIMEOUT)                     /* -2144317435, 0x80305005;  -2144251899, 0x80315005 */
#define AXCL_ERR_COMM_BUSY                      AXCL_DEF_COMM_ERR(AXCL_ERR_BUSY)                        /* -2144317434, 0x80305006;  -2144251898, 0x80315006 */
#define AXCL_ERR_COMM_NO_MEMORY                 AXCL_DEF_COMM_ERR(AXCL_ERR_NO_MEMORY)                   /* -2144317433, 0x80305007;  -2144251897, 0x80315007 */
/* module-specific: 0x20 ~ */
#define AXCL_ERR_COMM_FAIL                      AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x00)          /* 0x80X05020  general failure */
#define AXCL_ERR_COMM_NOT_OPEN                  AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x01)          /* 0x80X05021  comm not open */
#define AXCL_ERR_COMM_ALREADY_OPEN              AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x02)          /* 0x80X05022  comm already open */
#define AXCL_ERR_COMM_IO                        AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x03)          /* 0x80X05023  I/O error */
#define AXCL_ERR_COMM_CLOSED                    AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x04)          /* 0x80X05024  comm closed */
#define AXCL_ERR_COMM_INIT_FAILED               AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x05)          /* 0x80X05025  init failed */
#define AXCL_ERR_COMM_NOT_FOUND                 AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x06)          /* 0x80X05026  resource not found */
#define AXCL_ERR_COMM_STALE_PACKET              AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x07)          /* 0x80X05027  stale packet detected */
#define AXCL_ERR_COMM_SESSION_EXPIRED           AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x08)          /* 0x80X05028  session expired */
#define AXCL_ERR_COMM_PROTO_VIOLATION           AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x09)          /* 0x80X05029  protocol violation */
#define AXCL_ERR_COMM_INVALID_STATE             AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x0A)          /* 0x80X0502A  invalid state */
#define AXCL_ERR_COMM_CANCELED                  AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x0B)          /* 0x80X0502B  operation canceled */
#define AXCL_ERR_COMM_INTERRUPTED               AXCL_DEF_COMM_ERR(AXCL_ERR_MODULE_BASE + 0x0C)          /* 0x80X0502C  operation interrupted */

/****************************************************************************************************
 * protocol error
****************************************************************************************************/
#define AXCL_DEF_PROTOCOL_ERR(errid)            AXCL_DEF_ERR(AXCL_PROTOCOL, (errid))
                                                                                                        /*           HOST           |         DEVICE         */
#define AXCL_ERR_PROTOCOL_NULL_POINTER          AXCL_DEF_PROTOCOL_ERR(AXCL_ERR_NULL_POINTER)            /* -2144317182, 0x80305102;  -2144251646, 0x80315102 */
#define AXCL_ERR_PROTOCOL_ILLEGAL_PARAM         AXCL_DEF_PROTOCOL_ERR(AXCL_ERR_ILLEGAL_PARAM)           /* -2144317181, 0x80305103;  -2144251645, 0x80315103 */
#define AXCL_ERR_PROTOCOL_UNSUPPORT             AXCL_DEF_PROTOCOL_ERR(AXCL_ERR_UNSUPPORT)               /* -2144317180, 0x80305104;  -2144251644, 0x80315104 */

#define AXCL_ERR_PROTOCOL_FAIL                  AXCL_DEF_PROTOCOL_ERR(AXCL_ERR_MODULE_BASE + 0x00)      /* -2144317152, 0x80305120;  -2144251616, 0x80315120 */

/****************************************************************************************************
 * runtime error
****************************************************************************************************/
#define AXCL_DEF_RT_ERR(errid)                  AXCL_DEF_ERR(AXCL_RUNTIME, (errid))
                                                                                                        /*           HOST           |         DEVICE         */
#define AXCL_ERR_RT_NULL_POINTER                AXCL_DEF_RT_ERR(AXCL_ERR_NULL_POINTER)                  /* -2144316926, 0x80305202;  -2144251390, 0x80315202 */
#define AXCL_ERR_RT_ILLEGAL_PARAM               AXCL_DEF_RT_ERR(AXCL_ERR_ILLEGAL_PARAM)                 /* -2144316925, 0x80305203;  -2144251389, 0x80315203 */
#define AXCL_ERR_RT_UNSUPPORT                   AXCL_DEF_RT_ERR(AXCL_ERR_UNSUPPORT)                     /* -2144316924, 0x80305204;  -2144251388, 0x80315204 */
#define AXCL_ERR_RT_TIMEOUT                     AXCL_DEF_RT_ERR(AXCL_ERR_TIMEOUT)                       /* -2144316923, 0x80305205;  -2144251387, 0x80315205 */
#define AXCL_ERR_RT_BUSY                        AXCL_DEF_RT_ERR(AXCL_ERR_BUSY)                          /* -2144316922, 0x80305206;  -2144251386, 0x80315206 */
#define AXCL_ERR_RT_NO_MEMORY                   AXCL_DEF_RT_ERR(AXCL_ERR_NO_MEMORY)                     /* -2144316921, 0x80305207;  -2144251385, 0x80315207 */
#define AXCL_ERR_RT_ENCODE                      AXCL_DEF_RT_ERR(AXCL_ERR_ENCODE)                        /* -2144316920, 0x80305208;  -2144251384, 0x80315208 */
#define AXCL_ERR_RT_DECODE                      AXCL_DEF_RT_ERR(AXCL_ERR_DECODE)                        /* -2144316919, 0x80305209;  -2144251383, 0x80315209 */
#define AXCL_ERR_RT_UNEXPECT_RESPONSE           AXCL_DEF_RT_ERR(AXCL_ERR_UNEXPECT_RESPONSE)             /* -2144316918, 0x8030520A;  -2144251382, 0x8031520A */

#define AXCL_ERR_RT_FAIL                        AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x00)            /* -2144316896, 0x80305220;  -2144251360, 0x80315220 */
#define AXCL_ERR_RT_DESTROY_DEFAULT_CONTEXT     AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x01)            /* -2144316895, 0x80305221;  -2144251359, 0x80315221 */
#define AXCL_ERR_RT_DESTROY_DEFAULT_STREAM      AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x02)            /* -2144316894, 0x80305222;  -2144251358, 0x80315222 */
#define AXCL_ERR_RT_STREAM_NOT_EXIST            AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x03)            /* -2144316893, 0x80305223;  -2144251357, 0x80315223 */
#define AXCL_ERR_RT_CONTEXT_NOT_EXIST           AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x04)            /* -2144316892, 0x80305224;  -2144251356, 0x80315224 */
#define AXCL_ERR_RT_CREATE_CONTEXT              AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x05)            /* -2144316891, 0x80305225;  -2144251355, 0x80315225 */
#define AXCL_ERR_RT_CREATE_STREAM               AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x06)            /* -2144316890, 0x80305226;  -2144251354, 0x80315226 */
#define AXCL_ERR_RT_THREAD_NOT_BIND_CONTEXT     AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x07)            /* -2144316889, 0x80305227;  -2144251353, 0x80315227 */
#define AXCL_ERR_RT_DEVICE_NOT_ACTIVE           AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x08)            /* -2144316888, 0x80305228;  -2144251352, 0x80315228 */
#define AXCL_ERR_RT_DEFAULT_CONTEXT_NOT_EXIST   AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x09)            /* -2144316887, 0x80305229;  -2144251351, 0x80315229 */
#define AXCL_ERR_RT_DEVICE_NOT_EXIST            AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x0A)            /* -2144316886, 0x8030522A;  -2144251350, 0x8031522A */
#define AXCL_ERR_RT_SUBMIT_TASK                 AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x0B)            /* -2144316885, 0x8030522B;  -2144251349, 0x8031522B */
#define AXCL_ERR_RT_CONTEXT_NOT_DESTROYED       AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x0C)            /* -2144316884, 0x8030522C;  -2144251348, 0x8031522C */
#define AXCL_ERR_RT_STREAM_NOT_DESTROYED        AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x0D)            /* -2144316883, 0x8030522D;  -2144251347, 0x8031522D */
#define AXCL_ERR_RT_EVENT_NOT_EXIST             AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x0E)            /* -2144316882, 0x8030522E;  -2144251346, 0x8031522E */
#define AXCL_ERR_RT_CREATE_EVENT                AXCL_DEF_RT_ERR(AXCL_ERR_MODULE_BASE + 0x0F)            /* -2144316881, 0x8030522F;  -2144251345, 0x8031522F */

/****************************************************************************************************
 * native error
****************************************************************************************************/
#define AXCL_DEF_NATIVE_ERR(errid)              AXCL_DEF_ERR(AXCL_NATIVE, (errid))
#define AXCL_DEF_SYS_ERR(errid)                 AXCL_DEF_ERR(AXCL_SYS, (errid))
#define AXCL_DEF_VDEC_ERR(errid)                AXCL_DEF_ERR(AXCL_VDEC, (errid))
#define AXCL_DEF_VENC_ERR(errid)                AXCL_DEF_ERR(AXCL_VENC, (errid))
#define AXCL_DEF_IVPS_ERR(errid)                AXCL_DEF_ERR(AXCL_IVPS, (errid))
#define AXCL_DEF_IVE_ERR(errid)                 AXCL_DEF_ERR(AXCL_IVE, (errid))
#define AXCL_DEF_ENGINE_ERR(errid)              AXCL_DEF_ERR(AXCL_ENGINE, (errid))

/****************************************************************************************************
 * daemon error
 ****************************************************************************************************/
#define AXCL_DEF_DAEMON_ERR(errid)              AXCL_DEF_ERR(AXCL_DAEMON, (errid))
/* generic: 0x00 ~ 0x1F */
#define AXCL_ERR_DAEMON_NULL_POINTER            AXCL_DEF_DAEMON_ERR(AXCL_ERR_NULL_POINTER)              /* 0x80315502 */
#define AXCL_ERR_DAEMON_ILLEGAL_PARAM           AXCL_DEF_DAEMON_ERR(AXCL_ERR_ILLEGAL_PARAM)             /* 0x80315503 */
#define AXCL_ERR_DAEMON_TIMEOUT                 AXCL_DEF_DAEMON_ERR(AXCL_ERR_TIMEOUT)                   /* 0x80315505 */
#define AXCL_ERR_DAEMON_BUSY                    AXCL_DEF_DAEMON_ERR(AXCL_ERR_BUSY)                      /* 0x80315506 */
/* module-specific: 0x20 ~ */
#define AXCL_ERR_DAEMON_INIT_CONTROL            AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x00)        /* 0x80315520  control interface init failed */
#define AXCL_ERR_DAEMON_ALREADY_RUNNING         AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x01)        /* 0x80315521  daemon already running */
#define AXCL_ERR_DAEMON_WORKER_LIMIT            AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x02)        /* 0x80315522  worker count reached MAX_WORKERS */
#define AXCL_ERR_DAEMON_LAUNCH_WORKER           AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x03)        /* 0x80315523  vfork/execl failed */
#define AXCL_ERR_DAEMON_KILL_WORKER             AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x04)        /* 0x80315524  kill worker failed (D state) */
#define AXCL_ERR_DAEMON_WORKER_LOST             AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x05)        /* 0x80315525  worker exited unexpectedly */
#define AXCL_ERR_DAEMON_SEND_RESPONSE           AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x06)        /* 0x80315526  send_response to host failed */
#define AXCL_ERR_DAEMON_SINGLETON               AXCL_DEF_DAEMON_ERR(AXCL_ERR_MODULE_BASE + 0x07)        /* 0x80315527  another daemon instance running */

/****************************************************************************************************
 * worker error
 ****************************************************************************************************/
#define AXCL_DEF_WORKER_ERR(errid)              AXCL_DEF_ERR(AXCL_WORKER, (errid))
/* worker generic: 0x00 ~ 0x1F */
#define AXCL_ERR_WORKER_NULL_POINTER            AXCL_DEF_WORKER_ERR(AXCL_ERR_NULL_POINTER)              /* 0x80315602 */
#define AXCL_ERR_WORKER_ILLEGAL_PARAM           AXCL_DEF_WORKER_ERR(AXCL_ERR_ILLEGAL_PARAM)             /* 0x80315603 */
#define AXCL_ERR_WORKER_TIMEOUT                 AXCL_DEF_WORKER_ERR(AXCL_ERR_TIMEOUT)                   /* 0x80315605 */
#define AXCL_ERR_WORKER_BUSY                    AXCL_DEF_WORKER_ERR(AXCL_ERR_BUSY)                      /* 0x80315606 */
#define AXCL_ERR_WORKER_NO_MEMORY               AXCL_DEF_WORKER_ERR(AXCL_ERR_NO_MEMORY)                 /* 0x80315607 */
/* init/lifecycle: 0x20 ~ 0x2F */
#define AXCL_ERR_WORKER_INIT                    AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x00)        /* 0x80315620  worker init failed */
#define AXCL_ERR_WORKER_ALREADY_INIT            AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x01)        /* 0x80315621  already initialized */
#define AXCL_ERR_WORKER_NOT_INIT                AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x02)        /* 0x80315622  not initialized */
#define AXCL_ERR_WORKER_COMM_OPEN               AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x03)        /* 0x80315623  comm open failed */
#define AXCL_ERR_WORKER_NOT_FOUND               AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x04)        /* 0x80315624  generic not found */
#define AXCL_ERR_WORKER_ALREADY_EXISTS          AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x05)        /* 0x80315625  resource already exists */
/* context: 0x30 ~ 0x3F */
#define AXCL_ERR_WORKER_CTX_CREATE              AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x10)        /* 0x80315630  context creation failed */
#define AXCL_ERR_WORKER_CTX_NOT_FOUND           AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x11)        /* 0x80315631  context not found */
#define AXCL_ERR_WORKER_CTX_LIMIT               AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x12)        /* 0x80315632  context limit exceeded */
#define AXCL_ERR_WORKER_CTX_DESTROY_DEFAULT     AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x13)        /* 0x80315633  cannot destroy default context */
/* stream: 0x40 ~ 0x4F */
#define AXCL_ERR_WORKER_STREAM_CREATE           AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x20)        /* 0x80315640  stream creation failed */
#define AXCL_ERR_WORKER_STREAM_NOT_FOUND        AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x21)        /* 0x80315641  stream not found */
#define AXCL_ERR_WORKER_STREAM_LIMIT            AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x22)        /* 0x80315642  stream limit exceeded */
#define AXCL_ERR_WORKER_STREAM_SYNC             AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x23)        /* 0x80315643  stream sync failed */
#define AXCL_ERR_WORKER_STREAM_DESTROY_DEFAULT  AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x24)        /* 0x80315644  cannot destroy default stream */
#define AXCL_ERR_WORKER_STREAM_SYNC_IN_PROGRESS AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x25)        /* 0x80315645  concurrent SyncStream rejected */
#define AXCL_ERR_WORKER_STREAM_DESTROYED        AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x26)        /* 0x80315646  stream destroyed during wait */
#define AXCL_ERR_WORKER_STREAM_STICKY_ERROR     AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x27)        /* 0x80315647  task skipped due to sticky error */
/* event: 0x50 ~ 0x5F */
#define AXCL_ERR_WORKER_EVENT_CREATE            AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x30)        /* 0x80315650  event creation failed */
#define AXCL_ERR_WORKER_EVENT_NOT_FOUND         AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x31)        /* 0x80315651  event not found */
#define AXCL_ERR_WORKER_EVENT_LIMIT             AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x32)        /* 0x80315652  event limit exceeded */
#define AXCL_ERR_WORKER_EVENT_WAIT_TIMEOUT      AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x33)        /* 0x80315653  event wait timeout */
#define AXCL_ERR_WORKER_EVENT_DESTROYED         AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x34)        /* 0x80315654  event destroyed during wait */
#define AXCL_ERR_WORKER_EVENT_SYNC_IN_PROGRESS  AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x35)        /* 0x80315655  concurrent SyncEvent rejected */
#define AXCL_ERR_WORKER_EVENT_ALREADY_RECORDING AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x36)        /* 0x80315656  overlapping Record rejected */
/* dispatch/execute: 0x60 ~ 0x6F */
#define AXCL_ERR_WORKER_DISPATCH                AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x40)        /* 0x80315660  dispatch failed */
#define AXCL_ERR_WORKER_UNKNOWN_MODULE          AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x41)        /* 0x80315661  unknown module id */
#define AXCL_ERR_WORKER_UNKNOWN_API             AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x42)        /* 0x80315662  unknown api id */
#define AXCL_ERR_WORKER_DECODE                  AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x43)        /* 0x80315663  packet decode failed */
#define AXCL_ERR_WORKER_ENCODE                  AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x44)        /* 0x80315664  response encode failed */
#define AXCL_ERR_WORKER_EXECUTE                 AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x45)        /* 0x80315665  handler execution failed */
/* task/queue: 0x70 ~ 0x7F */
#define AXCL_ERR_WORKER_ENQUEUE                 AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x50)        /* 0x80315670  task enqueue failed */
#define AXCL_ERR_WORKER_TASK_CANCELLED          AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x51)        /* 0x80315671  task cancelled */
/* comm: 0x80 ~ 0x8F */
#define AXCL_ERR_WORKER_INTERRUPTED             AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x60)        /* 0x80315680  comm interrupted */
#define AXCL_ERR_WORKER_RECV_ERROR              AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x61)        /* 0x80315681  consecutive recv errors */
#define AXCL_ERR_WORKER_SDK_API                 AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x62)        /* 0x80315682  AX SDK API call failed */
/* callback: 0x90 ~ 0x9F */
#define AXCL_ERR_WORKER_ABORTED                 AXCL_DEF_WORKER_ERR(AXCL_ERR_MODULE_BASE + 0x70)        /* 0x80315690  operation aborted by shutdown */

/****************************************************************************************************
 * control error
 ****************************************************************************************************/
#define AXCL_DEF_CTRL_ERR(errid)                AXCL_DEF_ERR(AXCL_CTRL, (errid))
/* generic: 0x00 ~ 0x1F */
#define AXCL_ERR_CTRL_ILLEGAL_PARAM             AXCL_DEF_CTRL_ERR(AXCL_ERR_ILLEGAL_PARAM)               /* 0x80X05703 */
#define AXCL_ERR_CTRL_UNSUPPORT                 AXCL_DEF_CTRL_ERR(AXCL_ERR_UNSUPPORT)                   /* 0x80X05704 */
#define AXCL_ERR_CTRL_TIMEOUT                   AXCL_DEF_CTRL_ERR(AXCL_ERR_TIMEOUT)                     /* 0x80X05705 */
#define AXCL_ERR_CTRL_BUSY                      AXCL_DEF_CTRL_ERR(AXCL_ERR_BUSY)                        /* 0x80X05706 */
#define AXCL_ERR_CTRL_NO_MEMORY                 AXCL_DEF_CTRL_ERR(AXCL_ERR_NO_MEMORY)                   /* 0x80X05707 */
/* module-specific: 0x20 ~ */
#define AXCL_ERR_CTRL_FAIL                      AXCL_DEF_CTRL_ERR(AXCL_ERR_MODULE_BASE + 0x00)          /* 0x80X05720  general failure */
#define AXCL_ERR_CTRL_CLOSED                    AXCL_DEF_CTRL_ERR(AXCL_ERR_MODULE_BASE + 0x01)          /* 0x80X05721  not connected */
#define AXCL_ERR_CTRL_IO                        AXCL_DEF_CTRL_ERR(AXCL_ERR_MODULE_BASE + 0x02)          /* 0x80X05722  I/O error */
#define AXCL_ERR_CTRL_INTERRUPTED               AXCL_DEF_CTRL_ERR(AXCL_ERR_MODULE_BASE + 0x03)          /* 0x80X05723  operation interrupted */

#ifdef __cplusplus
}
#endif
// clang-format on

#endif /* __AXCL_ERROR_H__ */