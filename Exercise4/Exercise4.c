/*
File:			Exercise4.c	
Author:			Karri Korsu
Description:	Answers to Tasks 3 - 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRLEN 100

/*	Task 3	*/
int* createIntArray();
void numOfNeg(int array[]);
void sumOfInt(int array[]);
void sumOfPosDivThree(int array[]);

/*	Task 4	*/
int randNumGen(int num1, int num2);

/*	Misc	*/
void printArray(int array[]);
void printArrayTilZero(int array[]);



int main()
{
    int *intArray = createIntArray();

    numOfNeg(intArray);
	sumOfInt(intArray);
	sumOfPosDivThree(intArray);

    //printArray(intArray);
    
    return 0;
}


/*	3 Creates an array consisting of integers which the user inputs	*/
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


/*	3a Returns the amount of negative numbers in an array	*/
void numOfNeg(int array[])
{
    int numberOfNegs = 0;
	int i = 0;

	while (array[i] != 0)
	{
		if (array[i] < 0)
		{
			numberOfNegs++;
		}
		i++;
	}
    printf("number of negs: %d\n", numberOfNegs);
}


/*	3b Returns the sum of all integers in an array	*/
void sumOfInt(int array[])
{
	int sumOfIntegers = 0;
	int i = 0;
	while (array[i] != 0)
	{
		sumOfIntegers += array[i];
		i++;
	}
	printf("The sum of integers in the array: %d\n", sumOfIntegers);
}


/*	3c Returns the sum of positive integers in an array 
	which can be divided by three	*/
void sumOfPosDivThree(int array[])
{
	int sumOfPositives = 0;
	int i = 0;
	while (array[i] != 0)
	{
		if (array[i] > 0 && (array[i] % 3) == 0)
		{
		sumOfPositives += array[i];
		}
		i++;
	}
	printf("Sum of positive integers which can be divided by three: %d",
	 sumOfPositives);
}

/*	4a Returns a random integer in range which is taken as an argument*/
/*	Random number generator		*/
int randNumGen(int num1, int num2)
{
	time_t t = 0;
	srand((unsigned) time(&t));
	int range = 0;
	
	if (num1 > num2)
	{
		range = (num1 - num2 + 1) + num2;
	}
	else if (num2 < num1)
	{
		range = (num2 - num1 + 1) + num1;
	}
	
	int randNum = rand() % range;
	
	return randNum;
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
