# Structure Reference

<br>

## Structures


<br>

<a id="axclCrashDumpConfig"></a>

## axclCrashDumpConfig

Crash dump configuration structure.

<br>

### Fields

| Name | Type | Description |
|---|---|---|
| dump_dir | const char * | Dump file output directory. |
| dump_type | const char * | Dump type or level such as "Normal" or "FullMemory". |


<br>

<a id="axclrtEngineIODims"></a>

## axclrtEngineIODims

Tensor dimensions returned by engine shape query APIs.

<br>

### Fields

| Name | Type | Description |
|---|---|---|
| dimCount | int32_t | Number of valid dimensions in the shape. |
| dims | int32_t[AXCLRT_ENGINE_MAX_DIM_CNT] | Dimension values in logical tensor order. |


<br>

<a id="mockAttr"></a>

## mockAttr

Mock pipeline attributes.

<br>

### Fields

| Name | Type | Description |
|---|---|---|
| mode | uint32_t | Mock running mode. |
| param_a | uint32_t | Auxiliary parameter A. |
| param_b | uint32_t | Auxiliary parameter B. |

<br>

## Type Definitions


<br>

<a id="axclError"></a>

## axclError

Public AXCL error code type.

<br>

### Definition

```c
typedef int32_t axclError
```


<br>

<a id="axclrtContext"></a>

## axclrtContext

Runtime context handle.

<br>

### Definition

```c
typedef void* axclrtContext
```


<br>

<a id="axclrtEngineIO"></a>

## axclrtEngineIO

Opaque handle used to bind engine input and output buffers.

<br>

### Definition

```c
typedef void* axclrtEngineIO
```


<br>

<a id="axclrtEngineIOInfo"></a>

## axclrtEngineIOInfo

Opaque handle used to query engine input and output metadata.

<br>

### Definition

```c
typedef void* axclrtEngineIOInfo
```


<br>

<a id="axclrtEngineSet"></a>

## axclrtEngineSet

Bitmask describing the engine core affinity set.

<br>

### Definition

```c
typedef uint32_t axclrtEngineSet
```


<br>

<a id="axclrtEvent"></a>

## axclrtEvent

Runtime event handle.

<br>

### Definition

```c
typedef void* axclrtEvent
```


<br>

<a id="axclrtStream"></a>

## axclrtStream

Runtime stream handle.

<br>

### Definition

```c
typedef void* axclrtStream
```


<br>

<a id="mockCallbackAEx_t"></a>

## mockCallbackAEx_t

Callback invoked with a status code.

<br>

### Definition

```c
typedef int32_t(* mockCallbackAEx_t) (int32_t statusCode)
```


<br>

<a id="mockCallbackA_t"></a>

## mockCallbackA_t

Callback invoked with a status code and user context.

<br>

### Definition

```c
typedef int32_t(* mockCallbackA_t) (int32_t statusCode, void *userData)
```


<br>

<a id="mockCallbackBEx_t"></a>

## mockCallbackBEx_t

Callback invoked for group and frame notifications without user data.

<br>

### Definition

```c
typedef int32_t(* mockCallbackBEx_t) (uint32_t grp, uint32_t frameIndex)
```


<br>

<a id="mockCallbackB_t"></a>

## mockCallbackB_t

Callback invoked for group and frame notifications.

<br>

### Definition

```c
typedef int32_t(* mockCallbackB_t) (uint32_t grp, uint32_t frameIndex, void *userData)
```
