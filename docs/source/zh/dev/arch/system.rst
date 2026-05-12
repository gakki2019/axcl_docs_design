系统架构
========

文档生成链路如下：

.. code-block:: text

   include/external/*.h
       -> Doxygen XML
       -> Breathe / Exhale
       -> Sphinx HTML
       -> Read the Docs

第一阶段重点是验证链路可工作，而不是交付最终文案。
