Installation
============

Prepare a local documentation environment with the minimal dependencies described in the SOP.

.. code-block:: bash

   python3 -m venv .venv
   . .venv/bin/activate
   pip install -r docs/requirements.txt
   make -C docs html

Required system packages include ``doxygen`` and ``graphviz`` when full API pages are enabled.

Reference materials:

- `Read the Docs configuration file reference <https://docs.readthedocs.io/en/stable/config-file/v2.html>`_
- `Sphinx documentation <https://www.sphinx-doc.org/>`_
