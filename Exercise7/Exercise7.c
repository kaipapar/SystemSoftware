/* 
 * File:   			Exercise7.c
 * Author:			Karri Korsu
 * Description: 	Answers to system software exercise 7 tasks 	
 */

#include <stdio.h>
#include <stdlib.h>

#include "Sieve.h"
#include "Matrix.h"

int main() {
	
	testSieve();
	testMatrix();
	
//	2
	char* userInput = readUserInput();
	int *memoryPointer = NULL; 
	
	memoryPointer = (int*)malloc(100 * sizeof(int));
	
	if (checkUserInput(userInput) == 1 && memoryPointer != NULL)
	{
		sieveOfEra(userInput, memoryPointer);
	}
	else if (memoryPointer == NULL)
	{
		printf("Memory allocation failed. \n");
	}
	else 
	{
		printf("Enter an integer! \n");
	}
	
	free(memoryPointer);

//	3       
   	getLargestSum();  
     
    return 0;
}


