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
char* readUserInputArray();
char* readUserInputThermistor();
int checkUserInput(char* userInput);
int * checkNumArray(int *arrayPointer, int lenArray);

void lookUpTable();

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
	
	if (!(pointerToMemory))
	{
		//printf("Pointer to null: %p", pointerToMemory);
		printf("Your input is not in the array\n");
	}
	else
	{
		//printf("Your input is in the array at memory location: %p", pointerToMemory);
		printf("Your input is in the array: %d\n", *pointerToMemory);
	}
	
//	4c
	lookUpTable();
	
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

/*	Sorts integer from largest to smallest array using pointer arithmetic	*/
int * sortArray(int *arrayPointer, int lenArray)
{
	int cache = INT_MAX;
	int	*origPointer = arrayPointer;
	
	for (int i = 0; i < lenArray; i++)
	{
		for (int j = i+1; j < lenArray; j++)
		{
			if (*(arrayPointer + j) > *(arrayPointer + i))
			{
				cache = *(arrayPointer + i);
				*(arrayPointer + i) = *(arrayPointer + j);
				*(arrayPointer + j) = cache;
			}
		}
	}
	return origPointer;	
}

/*	Asks for user input and returns that input as char array	*/
char* readUserInputArray()
{
	char *array = (char*) malloc(ARRAYSIZE * sizeof(char*));
	printf("Enter an integer from the array: \n");
	scanf(" %s", array);

	return array;
}
char* readUserInputThermistor()
{
	char *array = (char*) malloc(ARRAYSIZE * sizeof(char*));
	printf("Enter an integer from 250 to 1000: \n");
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
				else if (userInput[i] == 46 || userInput[i] == 45)
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
	char* userInput = readUserInputArray();
	int *inputPointer = NULL;
	
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

//	
void lookUpTable()
{
	float lookUpTable[32][2] = { //format: {ADC, C}
							{250, 1.4},
							 {275, 4.0},
							  {300, 6.4},
							   {325, 8.8},
								{350, 11.1},
								 {375, 13.4},
								  {400, 15.6},
								   {425, 17.8},
									{450, 20.0},
									{475, 22.2},
									{500, 24.4},
									{525, 26.7},
									{550, 29.0},
									{575, 31.3},
									{600, 33.7},
									{625, 36.1},
									{650, 38.7},
									{675, 41.3},
									{700, 44.1},
									{725, 47.1},
									{750, 50.2},
									{775, 53.7},
									{784, 55.0},
									{825, 61.5},
									{850, 66.2},
									{875, 71.5},
									{900, 77.9},
									{925, 85.7},
									{937, 90.3},
									{950, 96.0},
									{975, 111.2},
									{1000, 139.5}};
	int userInputADC1 = 0;
	int userInputADC2 = 0;
	int nearestADC = 0;
	float nearestCelsius = 0.0;
	int userInput = 0;
	//	Printing the lookup table
	printf("This is a lookup table for 1k NTC thermistor: \n");								
	for (int i = 0; i <= 31; i++)
	{
		printf("ADC: %.0f -> Celsius: %.1f\n", lookUpTable[i][0], lookUpTable[i][1]);
	} 								
	
	char* userInputArr = readUserInputThermistor();

	if (checkUserInput(userInputArr) == 1 && 250 <= atoi(userInputArr) && atoi(userInputArr) <= 1000)
	{
		userInput = atoi(userInputArr);
		if(userInput < lookUpTable[0][0])
		{
			nearestADC = lookUpTable[0][0];
			nearestCelsius = lookUpTable[0][1];
		}
		else if (userInput > lookUpTable[31][0])
		{
			nearestADC = lookUpTable[31][0];
			nearestCelsius = lookUpTable[31][1];
		}
		else
		{
			for (int i = 1; i<=31; i++)
			{
				if (userInput < lookUpTable[i][0])
				{
					userInputADC1 = userInput - lookUpTable[i-1][0];
					userInputADC2 = lookUpTable[i][0] - userInput;
					
					if (userInputADC1 >= userInputADC2)
					{

						nearestADC = lookUpTable[i][0];
						nearestCelsius = lookUpTable[i][1];
					}
					else 
					{
						nearestADC = lookUpTable[i-1][0];
						nearestCelsius = lookUpTable[i-1][1];
					}
					break;
				}
			}	
		}	
		printf("This is the nearest ADC value: %d \nand Celsius value: %.1f \nto your input: %d\n", nearestADC, nearestCelsius, userInput);
	}
	else
	{
		printf("Incorrect input.\n");
	}		
	
	
}



