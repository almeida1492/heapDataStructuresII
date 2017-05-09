//Created by Henrique de Almeida in 05/09/2017

#include "P9-heap.h"
#include <string.h>

//This algorithm builds up a priority list for overbooking scenario

typedef struct{
	char name[20];
	int serial;
} customer;

int compareCustomers (void* cust1, void* cust2)
{
//	Local Definitions
	customer c1;
	customer c2;
	
//	Statements
	c1 = *(customer*)cust1;
	c2 = *(customer*)cust2;
	
	if (c1.serial < c2.serial)
	    return -1;
	else if (c1.serial == c2.serial)
	    return 0;
	return +1;
}	// compareCustomers

int main(){
//	Local declarations
	HEAP *heap;
	FILE *file;
	char temp[20], surTemp[10];
	customer *generator, *receiver;
	int sizeReceiver;

//	Statements
	file = fopen("customersList.txt", "r");
	heap = heapCreate(maxQueue, compareCustomers);

	while(fscanf(file, "%s", temp) != EOF){
		//	Local declarations
		int mileage, years, sequence, tempNum;

		//	Statements
		generator = (customer*) malloc(sizeof(customer)); 

		fscanf(file, "%s", surTemp);			//	reads the surname from input
		sprintf(temp, "%s %s", temp, surTemp);	//	concatenates name and surname
		strcpy(generator->name, temp);			//	and puts it into the struct

		fscanf(file, "%i", &mileage);			//	gets the customers' info from 
		fscanf(file, "%i", &years);				//	list
		fscanf(file, "%i", &sequence);			//

		tempNum = (mileage / 1000) + years - sequence;	//	serial production

		generator->serial = tempNum;

		/*printf("%s %i\n", generator->name, generator->serial);*/
		heapInsert(heap, generator);
	}

	sizeReceiver = heap->size;

	for (int i = 0; i < sizeReceiver; i++){
		receiver = (customer*) malloc(sizeof(customer));

		heapDelete(heap, (void**)&receiver);

		printf("%s %i\n", receiver->name, receiver->serial);
	}

	fclose(file);
	return 0;
}