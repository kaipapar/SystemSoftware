/*
File:			Exercise6.c
Author:			Karri Korsu
Description:	Answers to ex6 task 3 and 4c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 10

void printArray(int *arrayPointer, int lenArray);
int * randArray(int *arrayPointer, int lenArray);


int * sortArray(int *arrayPointer, int lenArray);
char* readUserInput();
int checkUserInput(char* userInput);
int * checkNumArray(int *arrayPointer, int lenArray);

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
	
	arrayPointer2 = &emptyArray[0];
	
	int *arrayPointer3 = randArray(arrayPointer2, ARRAYSIZE);
	printf("line 42\n");
	printArray(arrayPointer3, ARRAYSIZE);	
	
// 3c
	printf("line 46\n");
	int *arrayPointer4 = sortArray(arrayPointer3, ARRAYSIZE);
	
	printArray(arrayPointer4, ARRAYSIZE);	
	int *pointerToMemory = checkNumArray(arrayPointer4, ARRAYSIZE);
	printf(" %p\n ", pointerToMemory);
	if (pointerToMemory == 0)
	{
		//printf("Pointer to null: %p", pointerToMemory);
		printf("Your input is not in the array.\n");
	}
	else
	{
		//printf("Your input is in the array at memory location: %p", pointerToMemory);
		printf("Your input is in the array.\n");
	}
	
	return 0;
}



void printArray(int *arrayPointer, int lenArray)
{
    for (int i = 0; i < lenArray; i++)
    {
    	printf("array value %d\n", *arrayPointer);
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


int * sortArray(int *arrayPointer, int lenArray)
{
	int cache = INT_MIN;
	int	*origPointer = arrayPointer;
	
	for (int i = 0; i < lenArray; i++)
	{
		for (int j = i+1; j < lenArray; j++)
		{
			if (*(arrayPointer + j) < *(arrayPointer + i))
			{
				cache = *(arrayPointer + i); //or pointer+1
				*(arrayPointer + i) = *(arrayPointer + j);
				*(arrayPointer + j) = cache;
			}
		}
	}
	return origPointer;	
}

/*	Asks for user input and returns that input as char array	*/
char* readUserInput()
{
	char *array = (char*) malloc(ARRAYSIZE * sizeof(char*));
	printf("Enter an integer from the array: \n");
	scanf(" %s", array);

	return array;
}

/*	Checks whether userInput char array can be interpreted as integer
	returns 0 == False, 1 == True	*/
int checkUserInput(char* userInput)
{	//	if the first element is a dash or a number
	int flag = 2;
	if (userInput[0] == 45 || (userInput[0] >= 48 && userInput[0] <= 57))
	{	
	//	note this wont work on integers with more than 10 digits
		for (int i = 1; i < ARRAYSIZE; i++)	
		{
			if (userInput[i] >= 48 && userInput[i] <= 57)
			{	// if the element is a number: advance.
				flag = 1;
			}
			else 
			{					
				// if the element isnt a number 
				// for elements in userInput from i to end of array.
				if (userInput[i] == 0)
				{	// if the element is empty: advance.
					flag = 1;
				}
				else if (userInput[i] == 32)
				{	// if its something else than empty the input is invalid.
					flag = 0;
					break;
				}
			}
		}
	}
	else
	{
		flag = 0;
	}
	return flag;
}

	//  check if number in array using pointers, if in array print it else print pointer to null
	//	if num in array --> get the memory position of the num in array, else return pointer to NULL

int * checkNumArray(int *arrayPointer, int lenArray)
{
	//	read user input as char array
	char* userInput = readUserInput();
	int *inputPointer = NULL;
	int *origPointer = arrayPointer;
	
	if (checkUserInput(userInput) == 1)
	{
		int checkedInput = atoi(userInput);
		for (int i = 0; i < lenArray; i++)
		{
			if (checkedInput == *arrayPointer)
			{
				inputPointer = arrayPointer;
				break;
			}
			arrayPointer++;
		}

/*
		printf("Pointer to null: %p\n", inputPointer);

		printf("The input is in the array at location: %p \n", arrayPointer);
		*/
	}
	return inputPointer;
}






