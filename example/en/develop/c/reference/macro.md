# Macro Reference


<br>

<a id="AXCLRT_ENGINE_MAX_DIM_CNT"></a>

## AXCLRT_ENGINE_MAX_DIM_CNT

Maximum number of dimensions supported by an engine tensor.

<br>

### Definition

```c
#define AXCLRT_ENGINE_MAX_DIM_CNT 32
```


<br>

<a id="AXCL_COMM"></a>

## AXCL_COMM



<br>

### Definition

```c
#define AXCL_COMM (0x50)
```


<br>

<a id="AXCL_CTRL"></a>

## AXCL_CTRL



<br>

### Definition

```c
#define AXCL_CTRL (0x57)
```


<br>

<a id="AXCL_DAEMON"></a>

## AXCL_DAEMON



<br>

### Definition

```c
#define AXCL_DAEMON (0x55)
```


<br>

<a id="AXCL_DEF_COMM_ERR"></a>

## AXCL_DEF_COMM_ERR

Compose a common-module error code.

<br>

### Definition

```c
#define AXCL_DEF_COMM_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_COMM@@, (errid))
```


<br>

<a id="AXCL_DEF_CTRL_ERR"></a>

## AXCL_DEF_CTRL_ERR



<br>

### Definition

```c
#define AXCL_DEF_CTRL_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_CTRL@@, (errid))
```


<br>

<a id="AXCL_DEF_DAEMON_ERR"></a>

## AXCL_DEF_DAEMON_ERR

Compose a daemon-module error code.

<br>

### Definition

```c
#define AXCL_DEF_DAEMON_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_DAEMON@@, (errid))
```


<br>

<a id="AXCL_DEF_ENGINE_ERR"></a>

## AXCL_DEF_ENGINE_ERR

Compose an engine-module error code.

<br>

### Definition

```c
#define AXCL_DEF_ENGINE_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_ENGINE@@, (errid))
```


<br>

<a id="AXCL_DEF_ERR"></a>

## AXCL_DEF_ERR

Compose a module-specific AXCL error code.

<br>

### Definition

```c
#define AXCL_DEF_ERR ((@@REF:axclError@@)((0x80000000L) | ((@@REF:AX_ID_AXCL@@) << 16 ) | ((sub) << 8) | (errid)))
```


<br>

<a id="AXCL_DEF_IVE_ERR"></a>

## AXCL_DEF_IVE_ERR

Compose an IVE-module error code.

<br>

### Definition

```c
#define AXCL_DEF_IVE_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_IVE@@, (errid))
```


<br>

<a id="AXCL_DEF_IVPS_ERR"></a>

## AXCL_DEF_IVPS_ERR

Compose an IVPS-module error code.

<br>

### Definition

```c
#define AXCL_DEF_IVPS_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_IVPS@@, (errid))
```


<br>

<a id="AXCL_DEF_NATIVE_ERR"></a>

## AXCL_DEF_NATIVE_ERR

Compose a native-module error code.

<br>

### Definition

```c
#define AXCL_DEF_NATIVE_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_NATIVE@@, (errid))
```


<br>

<a id="AXCL_DEF_PROTOCOL_ERR"></a>

## AXCL_DEF_PROTOCOL_ERR

Compose a protocol-module error code.

<br>

### Definition

```c
#define AXCL_DEF_PROTOCOL_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_PROTOCOL@@, (errid))
```


<br>

<a id="AXCL_DEF_RT_ERR"></a>

## AXCL_DEF_RT_ERR

Compose a runtime-module error code.

<br>

### Definition

```c
#define AXCL_DEF_RT_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_RUNTIME@@, (errid))
```


<br>

<a id="AXCL_DEF_SYS_ERR"></a>

## AXCL_DEF_SYS_ERR

Compose a system-module error code.

<br>

### Definition

```c
#define AXCL_DEF_SYS_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_SYS@@, (errid))
```


<br>

<a id="AXCL_DEF_VDEC_ERR"></a>

## AXCL_DEF_VDEC_ERR

Compose a video-decode-module error code.

<br>

### Definition

```c
#define AXCL_DEF_VDEC_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_VDEC@@, (errid))
```


<br>

<a id="AXCL_DEF_VENC_ERR"></a>

## AXCL_DEF_VENC_ERR

Compose a video-encode-module error code.

<br>

### Definition

```c
#define AXCL_DEF_VENC_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_VENC@@, (errid))
```


<br>

<a id="AXCL_DEF_WORKER_ERR"></a>

## AXCL_DEF_WORKER_ERR



<br>

### Definition

```c
#define AXCL_DEF_WORKER_ERR @@REF:AXCL_DEF_ERR@@(@@REF:AXCL_WORKER@@, (errid))
```


<br>

<a id="AXCL_ENGINE"></a>

## AXCL_ENGINE



<br>

### Definition

```c
#define AXCL_ENGINE (0x1D)
```


<br>

<a id="AXCL_EXPORT"></a>

## AXCL_EXPORT



<br>

### Definition

```c
#define AXCL_EXPORT
```


<br>

<a id="AXCL_IVE"></a>

## AXCL_IVE



<br>

### Definition

```c
#define AXCL_IVE (0x15)
```


<br>

<a id="AXCL_IVPS"></a>

## AXCL_IVPS



<br>

### Definition

```c
#define AXCL_IVPS (0x0D)
```


<br>

<a id="AXCL_LITE"></a>

## AXCL_LITE



<br>

### Definition

```c
#define AXCL_LITE (0x53)
```


<br>

<a id="AXCL_NATIVE"></a>

## AXCL_NATIVE



<br>

### Definition

```c
#define AXCL_NATIVE (0x54)
```


<br>

<a id="AXCL_PROTOCOL"></a>

## AXCL_PROTOCOL



<br>

### Definition

```c
#define AXCL_PROTOCOL (0x51)
```


<br>

<a id="AXCL_RUNTIME"></a>

## AXCL_RUNTIME



<br>

### Definition

```c
#define AXCL_RUNTIME (0x52)
```


<br>

<a id="AXCL_SYS"></a>

## AXCL_SYS



<br>

### Definition

```c
#define AXCL_SYS (0x0B)
```


<br>

<a id="AXCL_VDEC"></a>

## AXCL_VDEC



<br>

### Definition

```c
#define AXCL_VDEC (0x08)
```


<br>

<a id="AXCL_VENC"></a>

## AXCL_VENC



<br>

### Definition

```c
#define AXCL_VENC (0x07)
```


<br>

<a id="AXCL_WORKER"></a>

## AXCL_WORKER



<br>

### Definition

```c
#define AXCL_WORKER (0x56)
```


<br>

<a id="AX_ID_AXCL"></a>

## AX_ID_AXCL



<br>

### Definition

```c
#define AX_ID_AXCL (0x30)
```


<br>

<a id="INVALID_AXCL_CONTEXT"></a>

## INVALID_AXCL_CONTEXT

Invalid runtime context handle.

<br>

### Definition

```c
#define INVALID_AXCL_CONTEXT ((@@REF:axclrtContext@@)0)
```


<br>

<a id="INVALID_AXCL_EVENT"></a>

## INVALID_AXCL_EVENT

Invalid runtime event handle.

<br>

### Definition

```c
#define INVALID_AXCL_EVENT ((@@REF:axclrtEvent@@ )0)
```


<br>

<a id="INVALID_AXCL_STREAM"></a>

## INVALID_AXCL_STREAM

Invalid runtime stream handle.

<br>

### Definition

```c
#define INVALID_AXCL_STREAM ((@@REF:axclrtStream@@ )0)
```


<br>

<a id="NO_TIMEOUT"></a>

## NO_TIMEOUT

Timeout value used to wait indefinitely.

<br>

### Definition

```c
#define NO_TIMEOUT (-1)
```
