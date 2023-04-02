/* 
 * File:   			Sieve.c
 * Author:			Karri Korsu
 * Description: 	An implementation of the sieve of erasthotenes for sys software ex7
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Sieve.h"



void testSieve() {

	printf("Hello from Sieve.\n");

}

void sieveOfEra(char* userInput, int *arrayPointer) 
{
	int posInteger = atoi(userInput);
	if (posInteger > 1 && posInteger < 25000)
	{
		// initialize all values to be true
		for (int i = 2; i < posInteger; i++)
		{
			*(arrayPointer + i) = 1;
		}
		
		// check true values for prime-ness
		for (int j = 2; j*j <= posInteger; j++)
		{
			if (*(arrayPointer + j) == 1)
			{	// multiples of j cannot be prime --> set them to false
				for (int k = j*j; k <= posInteger; k+=j)
				{
					*(arrayPointer + k) = 0;
				}
			}
		}
		// print primes
		for (int i = 2; i <= posInteger; i++)
		{
			if (*(arrayPointer + i) == 1)
			{
				printf("Prime number: %d \n", i);
			}
		}
		
	
	}
	else if (posInteger > 25000)
	{
		printf("Please input a smaller number. \n");
	}
	else 
	{
		printf("There are no prime numbers below your input. \n");
	}
}


/*	Asks for user input and returns that input as char array	*/
char* readUserInput()
{
	char *array = (char*) malloc(ARRAYSIZE * sizeof(char*));
	printf("Enter a positive integer: \n");
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





