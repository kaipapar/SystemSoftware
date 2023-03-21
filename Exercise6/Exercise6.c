/*
File:			Exercise6.c
Author:			Karri Korsu
Description:	Answers to ex6 task 3 and 4c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 10

void printArray(int *arrayPointer, int lenArray);
int * randArray(int *arrayPointer, int lenArray);

int main() 
{
// 3a
	int *arrayPointer = NULL;
	
	int intArray[ARRAYSIZE] ={1,2,3,4,5,6,7,8,9,10};
	
	arrayPointer = &intArray[0];
	
	printArray(arrayPointer, ARRAYSIZE);

// 3b	
	int *arrayPointer2 = NULL;
	
	int emptyArray[ARRAYSIZE] = {0};
	
	arrayPointer2 = &intArray[0];
	
	int *arrayPointer3 = randArray(arrayPointer2, ARRAYSIZE);
	
	printArray(arrayPointer3, ARRAYSIZE);	
	
// 3c
	
	
	return 0;
}



void printArray(int *arrayPointer, int lenArray)
{
	int i = 0;
    for (i = 0; i < lenArray; i++)
    {
    	
    	printf("arrayvalue %d\n", *arrayPointer);
    	arrayPointer++;
    }
}

int * randArray(int *arrayPointer, int lenArray)
{
	time_t t = 0;
	srand((unsigned) time(&t));
	
	// range is from 0 to 1 million
	int range = 1000000;
	int rangeShift = 0;	
	int *origPointer = arrayPointer;
	for (int i = 0; i < lenArray; i++)
	{
		*arrayPointer = rand() % range + rangeShift;
		arrayPointer++;
		
	}
	return origPointer;
}


void sortArray(int *arrayPointer, int lenArray)
{
	int cache = INT_MIN;
	for (int i = 0; i < lenArray; i++)
	{
		for (int j = i+1; j < lenArray; j++)
		{
			
			if (array[j] > array[i])
			{
				cache = array[i];
				array[i] = array[j];
				array[j] = cache;
			}
		}
	}
	// scan for number, error check, check if number in array using pointers, if in array print it else print pointer to null
}

