	/*
File:			Exercise5.c
Author:			Karri Korsu
Description:	Answers to tasks 3 and 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define MAXARRAY 50

void printArmstrong(char range[]);

void printIntArray(int array[], int lenArray);
void randArray(int array[], int lenArray);
void sortArray(int array[], int lenArray);

int main (int argc, char *argv[]) 
{
//	3a
	int i = 0;
	int flag = 0;
	int arglen = strlen(argv[1]);
/*	
	printf("Arguments: %d\n", argc);
	printf("Arg 1 : %s\n", argv[1]);
*/
	if (arglen <= 8 && argc == 2 && argv[1][0] >= 49 && argv[1][0] <= 57)
	{
		if (arglen == 8 && strcmp(argv[1],"10000000") != 0)
		{				
			flag = 0;
		}
		else if (arglen == 1)
		{
			flag = 1;
		}
		else
		{				
			for (i = 1; i < arglen; i++)
			{
				if (argv[1][i] >= 48 && argv[1][i] <= 57)
				{	// if the element is a number: advance.
					flag = 1;
				}
				else 
				{					
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
	
	if (flag == 1)
	{
		printf("This is your argument: %s \n", argv[1]);
		printArmstrong(argv[1]);
	}
	else
	{
		printf("Argument is not valid.\n");
	}

	
	printf("\nPrintArray:\n");	

	int array[] = {1, 5, 10, -10};
	int array1Len = sizeof(array) / sizeof(array[0]);
	
	printIntArray(array, array1Len);
	
	int randomArray[10] = {0};
	int array2Len = sizeof(randomArray) / sizeof(randomArray[0]);

	printf("\nRandom:\n");

	randArray(randomArray, array2Len);	
	printIntArray(randomArray, array2Len);

	printf("\n Sorted:\n");

	sortArray(randomArray, array2Len);
	printIntArray(randomArray, array2Len);

	printf("\n");

	return 0;
}

//	3b
void printArmstrong(char range[])
{
	int rangeInt = atoi(range);
	int cubedSum = 0;
	char nStr[MAXARRAY] = {'-'};
	
	for (int n = 1; n <= rangeInt; n++)
	{
		sprintf(nStr, "%d", n);
		
		int nStrLen = strlen(nStr);
		cubedSum = 0;
		
		for (int i = 0; i < nStrLen; i++)
		{
			int nEleInt = nStr[i] - '0';
			cubedSum += pow(nEleInt,nStrLen);
			
			//printf("n:%d, cubed sum;%d, nStr;x,nEleInt: %d\n",n, cubedSum, nEleInt);
		}

		if (n == cubedSum)
		{
			printf("%d is an armstrong number!\n", n);
		}
		
	}
}

//	4a
void printIntArray(int array[], int lenArray)
{
    for (int i = 0; i < lenArray; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
    }
}

//	4b
void randArray(int array[], int lenArray)
{
	time_t t = 0;
	srand((unsigned) time(&t));
	
	// range is from 0 to 1 million
	int range = 1000000;
	int rangeShift = 0;	
	
	for (int i = 0; i < lenArray; i++)
	{
		array[i] = rand() % range + rangeShift;
	}
}

//	4c
void sortArray(int array[], int lenArray)
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
}


