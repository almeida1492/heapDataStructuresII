#include "P9-heap.h"
#include <math.h>

typedef struct{
   void** heapAry;
   int    last;
   int    size;
   int    (*compare) (void* argu1, void* argu2);
   int    maxSize;
   int 	  count;
   int    count2;
} heapToAnalyze;

heapToAnalyze* heapCreateToAnalyze (int maxSize, int  (*compare) (void* argu1, void* argu2))
{
//	Local Definitions
	heapToAnalyze* heap;

//	Statements 
	heap = (heapToAnalyze*)malloc(sizeof (heapToAnalyze));
	if (!heap)
	   return NULL;

	heap->last    = -1;
	heap->compare = compare;
	heap->size = 0;
	heap->count = 0;
	heap->count2 = 0;

	// Force heap size to power of 2 -1
	heap->maxSize = (int) pow (2, ceil(log2(maxSize))) - 1;
	heap->heapAry = (void*)calloc(heap->maxSize, sizeof(void*));
	return heap;
}

void upToAnalyze (heapToAnalyze* heap, int childLoc){
//	Local Definitions 
	int    parent;
	void** heapAry;
	void*  hold;

//	Statements 
	// if not at root of heap -- index 0 
	if (childLoc)
	   {
	    heapAry = heap->heapAry;
	    parent = (childLoc - 1)/ 2;
	    if (heap->compare(heapAry[childLoc], heapAry[parent]) > 0)
	        // child is greater than parent -- swap 
	        {
	         hold             = heapAry[parent]; 
	         heapAry[parent]  = heapAry[childLoc];
	         heapAry[childLoc] = hold;
	        upToAnalyze (heap, parent);
	       } // if heap[] 
	   } // if newNode 
	heap->count++;
	return;
}

void DownToAnalyze (heapToAnalyze* heap, int root)
{
//	Local Definitions 
	void* hold;
	void* leftData;
	void* rightData;
	int   largeLoc;
	int   last;
	
//	Statements 
	last = heap->last;
	if ((root * 2 + 1) <= last)         // left subtree
	    // There is at least one child 
	   {
	    leftData   = heap->heapAry[root * 2 + 1];
	    if ((root * 2 + 2) <= last)  // right subtree 
	       rightData = heap->heapAry[root * 2 + 2];
	    else
	       rightData = NULL;
	       
	    // Determine which child is larger 
	    if ((!rightData) 
	         || heap->compare (leftData, rightData) > 0)
	       {
	        largeLoc = root * 2 + 1;
	       } // if no right key or leftKey greater
	    else
	       {
	        largeLoc = root * 2 + 2;
	       } // else 
	    // Test if root > larger subtree 
	    if (heap->compare (heap->heapAry[root], 
	        heap->heapAry[largeLoc]) < 0)
	        {
	         // parent < children 
	         hold                = heap->heapAry[root]; 
	         heap->heapAry[root] = heap->heapAry[largeLoc];
	         heap->heapAry[largeLoc] = hold;
	         DownToAnalyze (heap, largeLoc);
	        } // if root < 
	    heap->count2++;
	} // if root 
	return;
}

bool heapDeleteTA (heapToAnalyze* heap, void** dataOutPtr){
//	Statements 
	if (heap->size == 0)
	    // heap empty 
	    return false;
	*dataOutPtr = heap->heapAry[0];
	heap->heapAry[0]  = heap->heapAry[heap->last];
	(heap->last)--;
	(heap->size)--;
	DownToAnalyze(heap, 0);
	return true;
}

int main (){
	//	Local definitions
	heapToAnalyze *heap;
	int *num;
	const int arraySize = 10;

	//	Statements
	heap = heapCreateToAnalyze(maxQueue, compareInt);

	for (int i = 0; i < arraySize; i++){
		num = (int*) malloc(sizeof(int));
		*num = i + 1;
		heap->heapAry[i] = num;
		heap->last = i;
		heap->size++;
		upToAnalyze(heap, i);
	}

	num = (int*) malloc(sizeof(int));
	*num = arraySize;
	heap->heapAry[arraySize] = num;
	heap->last = arraySize;
	heap->size++;
	heap->count = 0;
	upToAnalyze(heap, arraySize);



	for (int i = 0; i < arraySize; i++){
		num = (int*) malloc(sizeof(int));
		heapDeleteTA(heap, (void**)&num);
		printf("%i\n", *num);
	}

	printf("\n\nArray de tamanho: %i\n", arraySize);
	printf("\nreheapUp 	-> %i movimentações\n", heap->count);
	printf("\nreheapDown 	-> %i movimentações\n", heap->count2);
	printf("\nO(logn)\n\n");
}

//	01 ----- 00, 00
//	02 ----- 01, 00
//  03 ----- 02, 01
//	04 ----- 04, 02
//	05 ----- 06, 04
//	06 ----- 08, 05
//	07 ----- 10, 07
//	08 ----- 13, 09
//	09 ----- 16, 12
//	20 ----- 54, 44






























