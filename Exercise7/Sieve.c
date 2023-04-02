/* 
 * File:   			Sieve.c
 * Author:			Karri Korsu
 * Description: 	An implementation of the sieve of erasthotenes for sys software ex7
 */

#include <stdio.h>
#include "Sieve.h"

#define ARRAYSIZE 10

void testSieve() {

	printf("Hello from Sieve.\n");
	
	
	// ask user for an input to define an upper limit for the primes
		//use user input function from previous exercise - returns a char array --> needs to be error checked and changed into an integer (n)
	
	// create an array sizeof n, with malloc, fill the array with numbers from 2-n, use pointer arithmetics
	
	// mark all numbers that are divisible by the iterator while iterator² is less or equal to n by changing their value to 0, when looping through the array 
	
	// return array elements that are not 0

}

void sieveOfEra(int posInteger) 
{
	if (posInteger > 1)
	{
	
	
	}
	else 
	{
		printf("Your integer isn't a prime number. \n");
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

int * checkNumArray(int *arrayPointer, int lenArray)
{
	//	read user input as char array
	char* userInput = readUserInput();
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

	}
	return inputPointer; 
}




