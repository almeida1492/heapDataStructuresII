#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#include "P9-heap.h"

int main(){
	HEAP *prQueue1, *prQueue2;
	char exit, bufferCleaner;
	CUST *cust;
	bool result;
	int numCusts = 0;
	
	prQueue1 = heapCreate(maxQueue, compareCust);
	prQueue2 = heapCreate(maxQueue, compareCust);

	printf("\n ------ Queue 1 ------");
	printf("\n Type q to exit\n");
	printf(" Type y to continue adding\n\n");

	do{
		cust = getCust();
		cust->serial = cust->priority * 1000 + (1000 - numCusts);
		result = heapInsert(prQueue1, cust);

		printf("Keep adding?\n");
		scanf("%c%c", &bufferCleaner, &exit);
	} while(exit != 'q');

	printf("\n ------ Queue 2 ------");
	printf("\n Type q to exit\n");
	printf(" Type y to continue adding\n\n");

	do{
		cust = getCust();
		cust->serial = cust->priority * 1000 + (1000 - numCusts);
		result = heapInsert(prQueue2, cust);

		printf("Keep adding?\n");
		scanf("%c%c", &bufferCleaner, &exit);
	} while(exit != 'q');

	return 0;
}