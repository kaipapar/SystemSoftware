/* 
 * File:   			Exercise7.c
 * Author:			Karri Korsu
 * Description: 	Answers to system software exercise 7 tasks 	
 */

#include <stdio.h>

#include "Sieve.h"
#include "Matrix.h"

#define ARRAYSIZE 10 // do macros carry over from other files ?

int main() {
	
	testSieve();
	testMatrix();
	
//	2
	char* userInput = userInput();
	
	
	if (checkUserInput(userInput) == 1)
	{
		sieveOfEra(userInput);
	}
	else 
	{
		printf("Enter an integer! \n");
	}

//	3       
   	getLargestSum();  
     
    return 0;
}


