//	Structure Declarations	typedef struct	   {	    int  id;	    int  priority;	    int  serial;	   } CUST;//	Constant Definitions	const int maxQueue = 20;#include <stdlib.h>#include "P9-01.h"		// Heap Structure#include "P9-02.h"		// Create Heap#include "P9-03.h"		// Insert Heap#include "P9-04.h"		// Reheap Up#include "P9-05.h"		// Delete Heap#include "P9-06.h"		// Reheap Down#include "compareCust.h"#include "getCust.h"#include "heapCount.h"//  Functions' prototypesCUST*	getCust			(void);int		compareCust		(void* cust1, void* cust2);int  	heapCount 		(HEAP* heap);bool 	heapFull  		(HEAP* heap);bool 	heapEmpty 		(HEAP* heap);