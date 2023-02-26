	/*
File:			Exercise5.c
Author:			Karri Korsu
Description:	Answers to tasks 3 and 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYLENGTH 5

void printArray(char* array, int lenArray);

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
	if (arglen <= 7 && argc == 2)
	{
		if (argv[1][0] == 45 || (argv[1][0] >= 48 && argv[1][0] <= 57))
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
	}
	else
	{
		printf("Argument is not valid.\n");
	}
	
	char array[ARRAYLENGTH] = {'a', 'b', 'c', 1, 5};
	int arrayLen = ARRAYLENGTH;
	
	printArray(array, arrayLen);
	

	return 0;
}

//	4a
void printArray(char array[], int lenArray)
{

// this is problematic. How to have int and char in same array and handle them efficiently. How to check if an element is char or int or etx??

    for (int i = 0; i < lenArray; i++)
    {
        if (sizeof(array[i]) == sizeof(char))
        {
        	printf("array element %d: %c\n", i, array[i]);
    	}
    	else //if (sizeof(array[i]) == sizeof(int))
    	{
    		printf("array element %d: %d\n", i, array[i]);
    	}
    }
}

