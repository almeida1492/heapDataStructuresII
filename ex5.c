//Created by Henrique de Almeida in 05/02/2017

#include "P9-heap.h"

//This algorithm heapifies a array using the reheapDown method

int main(){
//	Local definitions
	HEAP *heap;
	int pivot, *temp;
	int array[] = {16, 12, 15, 53, 81, 27, 30, 2, 50, 92, 6};
	
//	Statements
	heap = (HEAP*)malloc(sizeof(HEAP));
	heap = heapCreate(maxQueue, compareInt);

	for (int i = 0; i < 11; i++){
		temp = (int*) malloc(sizeof(int)); //	This for makes a copy of the array in the heap structure
		*temp = array[i];
		heap->heapAry[i] = temp;
	}

	printf("\n\n before heapDown	-> [");
	for (int i = 0; i < 11; ++i){
		temp = (int*) malloc(sizeof(int)); //	Printing array before heapfying it
		temp = heap->heapAry[i];
		printf("%i, ", *temp);
	}
	printf("]\n");

	heap->last = 10;
	pivot = (10/2) - 1; 					//	10 is the array size and this line finds the last parent

	for (int subRoot = pivot; subRoot >= 0; subRoot--){ //	
		_reheapDown(heap, subRoot);						//	algorithm's core
	}													//

	printf("\n\n after heapDown		-> [");
	for (int i = 0; i < 11; ++i){
		temp = (int*) malloc(sizeof(int)); //	Printing array after heapfying it
		temp = heap->heapAry[i];
		printf("%i, ", *temp);
	}
	printf("]\n\n");
}