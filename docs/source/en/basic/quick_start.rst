Quick Start
===========

This placeholder page shows the minimum AXCL initialization flow used across examples.

.. code-block:: c

   #include "axcl.h"

   int main(void) {
       if (axclInit(NULL) != AXCL_SUCC) {
           return -1;
       }

       axclFinalize();
       return 0;
   }

Next steps:

1. Read the architecture notes in :doc:`../dev/arch/system`.
2. Review device lifecycle behavior in :doc:`../dev/arch/device`.
3. Open the generated API landing page from :doc:`../dev/c/index`.
