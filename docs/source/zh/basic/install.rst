安装
====

本页展示最小可用的本地文档构建命令。

.. code-block:: bash

   python3 -m venv .venv
   . .venv/bin/activate
   pip install -r docs/requirements.txt
   make -C docs html

如果需要完整 API 生成，请确认系统已安装 ``doxygen`` 和 ``graphviz``。
