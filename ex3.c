#include "P9-heap.h"

const int arraySize = 5;

int main(){
	HEAP *heap;
	int *container;

	heap = (HEAP*)malloc(sizeof(HEAP));

	heap = heapCreate(maxQueue, compareInt);

	for (int i = 0; i < arraySize; i++){
		container = (int*)malloc(sizeof(int));

		*container = rand()%10000;
		heapInsert(heap, container);
	}
}