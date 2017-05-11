#include "P9-heap.h"

const int arraySize = 2000;

int main(){
	HEAP *heap;
	int *container;

	heap = (HEAP*)malloc(sizeof(HEAP));

	heap = heapCreate(maxQueue, compareInt);

	for (int i = 0; i < arraySize; i++){
		container = (int*)malloc(sizeof(int));

		*container = rand()%100;
		printf("%i\n", *container);
		heapInsert(heap, container);
	}
}

//	100		- real	0m0.004s
//	200		- real	0m0.005s
//	500		- real	0m0.005s
//	1000	- real	0m0.006s
//	2000	- real	0m0.008s