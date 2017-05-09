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
	char temp[20], surTemp[10];
	int *tempNum;
	customer *generator;

//	Statements
	file = fopen("customersList.txt", "r");

	while(fscanf(file, "%s", temp) != EOF){
		//	Statements
		generator = (customer*) malloc(sizeof(customer)); 

		fscanf(file, "%s", surTemp);			//	reads the surname from input
		sprintf(temp, "%s %s", temp, surTemp);	//	concatenates name and surname
		strcpy(generator->name, temp);			//	and puts it into the struct

		fscanf(file, "%i", tempNum);			//
		generator->mileage = *tempNum;			//
												//
		fscanf(file, "%i", tempNum);			//	fullfils the int struct slots 
		generator->years = *tempNum;			//	that were left empty
												//
		fscanf(file, "%i", tempNum);			//
		generator->sequence = *tempNum;			//
		
		printf("%s \n", temp);
	}

	fclose(file);
	return 0;
}