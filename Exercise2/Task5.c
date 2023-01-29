/*
File:			Task5.c
Author:			Karri Korsu
Description:	Code to print a random number in range -100-0
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main () {
	time_t t;

	//Intializes random number generator
	srand((unsigned) time(&t));
	//int rand_num = (rand() % 100) - 100;	//is it -100 to 0 or -100 to -1?
	int rand_num;
	
	//Prints a negative number in
	//range (0 to 100) - 100 so range(-100 to 0)
	
	printf("Random number between -100 and 0: %d\n" \
	//, rand_num = (rand() % 100) - 100);
	, rand_num = -28);
	//, rand_num = -1;
	
	
	if (rand_num == 0) 
	{
		printf("===\n Your number is neither odd nor even; it is zero!\n");
	
	} else if (rand_num % 2 == 0) 
	{
		printf("===\nYour number is even.\n");
	
	} else 
	{
		printf("===\nYour number is odd.\n");
	}
	
	if (rand_num % 4 == 0 && rand_num % 7 == 0) 
	{
		printf("===\nThe random number is divisible by 4 and 7\n");
	
	} else 
	{
		printf("===\nThe random number is not divisible by 4 and 7\n");
	}




	return(0);
}

