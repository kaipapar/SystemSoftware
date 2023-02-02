/*
File:			macroDemo.c
Author:			Karri Korsu
Description:	Macro and constant demo
*/

#include <stdio.h>

#define SIZE 5

void createArray() 
	{


	int demoArray[SIZE] = {1, 2, 3, 4, 5};
	
	demoArray[3] = 10;
	
	// print out array items
	for (int i = 0; i < SIZE; i++) 
	{
		printf("Array slot: %d where value is: %d\n", i, demoArray[i]);
	
	}
	
	}

int main() {

	printf("hello\n");

	createArray();

	return 0;

}
