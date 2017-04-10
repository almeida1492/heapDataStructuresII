/*	==================== heapCreate ====================	Allocates memory for heap and returns address of	heap head structure.	   Pre  Nothing	   Post heap created and address returned	             if memory overflow, NULL returned*/#include <math.h>HEAP* heapCreate (int maxSize, int  (*compare) (void* argu1, void* argu2)){//	Local Definitions	HEAP* heap;//	Statements 	heap = (HEAP*)malloc(sizeof (HEAP));	if (!heap)	   return NULL;	heap->last    = -1;	heap->compare = compare;	heap->size = 0;	// Force heap size to power of 2 -1	heap->maxSize = (int) pow (2, ceil(log2(maxSize))) - 1;	heap->heapAry = (void*) 	                 calloc(heap->maxSize, sizeof(void*));	return heap;}	// createHeap 