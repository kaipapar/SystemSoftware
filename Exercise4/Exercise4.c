/*
File:			Exercise4.c	
Author:			Karri Korsu
Description:	Answers to tasks 3 - 5
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRLEN 100

int* createIntArray();
void numOfNeg(int array[]);
void sumOfInt(int array[]);

void printArray(int array[]);
void printArrayTilZero(int array[]);



int main()
{
    int *intArray = createIntArray();

    numOfNeg(intArray);
	sumOfInt(intArray);

    //printArray(intArray);
    
    return 0;
}

/*	Creates an array consisting of integers which the user inputs	*/
int* createIntArray()
{
    int *array = (int*)malloc(ARRLEN * sizeof(int));
    int i = 0;
    printf("Enter an integer:");

    while (scanf("%d", &array[i]) == 1)
    {
        printf("You entered integer: %d \n", array[i]);
        if (array[i] == 0)
        {
            break;
        }
        else 
        {
            i++;
        }
    }
    printf("You entered 0 or something that isn't an integer!\n");

    return array;
}

/*	Returns the amount of negative numbers in an array	*/
void numOfNeg(int array[])
{
    int numberOfNegs = 0;
    for (int i = 0; i < ARRLEN; i++)
    {
        if (array[i] < 0)
        {
            numberOfNegs++;
        }
        else if (array[i] == 0)
        {
            break;
        }
    }
    printf("number of negs: %d\n", numberOfNegs);
}

/*	Returns the sum of all integers in an array	*/
void sumOfInt(int array[])
{
	int sumOfIntegers = 0;
	for (int i = 0; i < ARRLEN; i++)
	{
		if (array[i] == 0)
		{
			break;
		}
		else
		{
			sumOfIntegers += array[i];
		}
	}
	printf("The sum of integers in the array: %d\n", sumOfIntegers);
}


/*	Prints all elements of an integer array	*/
void printArray(int array[])
{
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
    }
}

/*	Prints all elements of an integer array until the next element is 0*/
void printArrayTilZero(int array[])
{
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
		if (array[i] == 0)
		{
			break;
		}
    }
}
