# Event API

## Index

- [Event API](#event-api)
  - [Index](#index)
  - [API](#api)
    - [axclrtCreateEvent](#axclrtcreateevent)
      - [Function](#function)
      - [Parameters](#parameters)
      - [Returns](#returns)
    - [axclrtDestroyEvent](#axclrtdestroyevent)
      - [Function](#function-1)
      - [Parameters](#parameters-1)
      - [Returns](#returns-1)
    - [axclrtRecordEvent](#axclrtrecordevent)
      - [Function](#function-2)
      - [Parameters](#parameters-2)
      - [Returns](#returns-2)
    - [axclrtStreamWaitEvent](#axclrtstreamwaitevent)
      - [Function](#function-3)
      - [Parameters](#parameters-3)
      - [Returns](#returns-3)
    - [axclrtStreamWaitEventWithTimeout](#axclrtstreamwaiteventwithtimeout)
      - [Function](#function-4)
      - [Parameters](#parameters-4)
      - [Returns](#returns-4)
    - [axclrtSynchronizeEvent](#axclrtsynchronizeevent)
      - [Function](#function-5)
      - [Parameters](#parameters-5)
      - [Returns](#returns-5)
    - [axclrtSynchronizeEventWithTimeout](#axclrtsynchronizeeventwithtimeout)
      - [Function](#function-6)
      - [Parameters](#parameters-6)
      - [Returns](#returns-6)

<br>

## API

<a id="axclrtCreateEvent"></a>

### axclrtCreateEvent

Create an event.

#### Function

```c
AXCL_EXPORT axclError axclrtCreateEvent(axclrtEvent *event);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| event | out | pointer to created event |

#### Returns

- `AXCL_SUCC`: success.
- `others`: failure.

<br>

<a id="axclrtDestroyEvent"></a>

### axclrtDestroyEvent

Destroy an event.

#### Function

```c
AXCL_EXPORT axclError axclrtDestroyEvent(axclrtEvent event);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| event | in | event created by [axclrtCreateEvent](#axclrtCreateEvent) to destroy. |

#### Returns

- `AXCL_SUCC`: success.
- `others`: failure.

<br>

<a id="axclrtRecordEvent"></a>

### axclrtRecordEvent

Record an event on a stream.

#### Function

```c
AXCL_EXPORT axclError axclrtRecordEvent(axclrtEvent event, axclrtStream stream);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| event | in | event created by [axclrtCreateEvent](#axclrtCreateEvent) to record. |
| stream | in | stream created by [axclrtCreateStream](stream_api.md#axclrtCreateStream) to record the event. |

#### Returns

N/A

<br>

<a id="axclrtStreamWaitEvent"></a>

### axclrtStreamWaitEvent

Wait for an event on a stream.

#### Function

```c
AXCL_EXPORT axclError axclrtStreamWaitEvent(axclrtStream stream, axclrtEvent event);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| stream | in | stream created by [axclrtCreateStream](stream_api.md#axclrtCreateStream) to wait for the event. |
| event | in | event created by [axclrtCreateEvent](#axclrtCreateEvent) to wait for. |

#### Returns

N/A

<br>

<a id="axclrtStreamWaitEventWithTimeout"></a>

### axclrtStreamWaitEventWithTimeout

Wait for an event on a stream with timeout.

#### Function

```c
AXCL_EXPORT axclError axclrtStreamWaitEventWithTimeout(axclrtStream stream, axclrtEvent event, int32_t timeout);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| stream | in | stream created by [axclrtCreateStream](stream_api.md#axclrtCreateStream) to wait for the event. |
| event | in | event created by [axclrtCreateEvent](#axclrtCreateEvent) to wait for. |
| timeout | in | timeout in milliseconds, -1 for no timeout. |

#### Returns

N/A

<br>

<a id="axclrtSynchronizeEvent"></a>

### axclrtSynchronizeEvent

Block host until the event is signaled (recorded).

#### Function

```c
AXCL_EXPORT axclError axclrtSynchronizeEvent(axclrtEvent event);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| event | in | event created by [axclrtCreateEvent](#axclrtCreateEvent) to wait for. |

#### Returns

- `AXCL_SUCC`: success.
- `others`: failure.

<br>

<a id="axclrtSynchronizeEventWithTimeout"></a>

### axclrtSynchronizeEventWithTimeout

Block host until the event is signaled (recorded) with timeout.

#### Function

```c
AXCL_EXPORT axclError axclrtSynchronizeEventWithTimeout(axclrtEvent event, int32_t timeout);
```

#### Parameters

| Name | Direction | Description |
|---|---|---|
| event | in | event created by [axclrtCreateEvent](#axclrtCreateEvent) to wait for. |
| timeout | in | timeout in milliseconds, -1 for no timeout. |

#### Returns

- `AXCL_SUCC`: success.
- `others`: failure.
