#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#include "P9-heap.h"

int main(){
	HEAP *prQueue1, *prQueue2, *prQueue3;
	char exit, bufferCleaner;
	CUST *cust;
	bool result;
	int numCusts = 0;
	int counter;
	
	prQueue1 = heapCreate(maxQueue, compareCust);
	prQueue2 = heapCreate(maxQueue, compareCust);
	prQueue3 = heapCreate(maxQueue, compareCust);

	printf("\n ------ Queue 1 ------");
	printf("\n Type q to exit\n");
	printf(" Type y to continue adding\n\n");

	//Fill queue 1
	do{
		cust = getCust();
		numCusts++;
		cust->serial = cust->priority * 1000 + (1000 - numCusts);
		result = heapInsert(prQueue1, cust);

		printf("Keep adding?\n");
		scanf("%c%c", &bufferCleaner, &exit);
	} while(exit != 'q');

	printf("\n ------ Queue 2 ------");
	printf("\n Type q to exit\n");
	printf(" Type y to continue adding\n\n");

	//Fill queue 2
	do{
		cust = getCust();
		numCusts++;
		cust->serial = cust->priority * 1000 + (1000 - numCusts);
		result = heapInsert(prQueue2, cust);

		printf("Keep adding?\n");
		scanf("%c%c", &bufferCleaner, &exit);
	} while(exit != 'q');


	//Merge
	counter = heapCount(prQueue1);
	for (int i = 0; i < counter; i++){
		cust = (CUST*)malloc(sizeof (CUST));

		result = heapDelete(prQueue1, (void**)&cust);

		if (!result)
			printf("Error: customer not found\n");
		else{
			heapInsert(prQueue3, cust);
		}
	}
	counter = heapCount(prQueue2);
	for (int i = 0; i < counter; i++){
		cust = (CUST*)malloc(sizeof (CUST));

		result = heapDelete(prQueue2, (void**)&cust);

		if (!result)
			printf("Error: customer not found\n");
		else{
			heapInsert(prQueue3, cust);
		}
	}

	//Output
	printf("\n 	");

	counter = heapCount(prQueue3);
	for (int i = 0; i < counter; i++){
		heapDelete(prQueue3, (void**)&cust);
		printf("->[%i]", cust->id);
	}

	printf("\n\n");
	return 0;
}



















