Device Runtime Notes
====================

This placeholder page documents the runtime lifecycle at a high level.

Typical order:

1. call ``axclInit``;
2. bind a device with ``axclrtSetDevice``;
3. create explicit contexts and streams as needed;
4. destroy streams and contexts;
5. reset the device and finalize the runtime.

For API details, continue to :doc:`../c/index`.
