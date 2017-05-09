//Created by Henrique de Almeida in 05/09/2017

#include "P9-heap.h"
#include <string.h>

//This algorithm builds up a priority list for overbooking scenario

typedef struct{
	char name[20];
	int mileage;
	int years;
	int sequence;
} customer;

int main(){
//	Local declarations
	FILE *file;
	char temp[10];

//	Statements
	file = fopen("customersList.txt", "r");

	while(fscanf(file, "%s", temp) != EOF){
		printf("%s \n", temp);
	}

	fclose(file);
	return 0;
}