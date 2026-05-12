System Architecture
===================

The documentation pipeline follows this simplified flow:

.. code-block:: text

   include/external/*.h
       -> Doxygen XML
       -> Breathe / Exhale
       -> Sphinx HTML
       -> Read the Docs hosting

The repository keeps generated artifacts out of Git and treats the public headers as the single source of truth for API reference content.
