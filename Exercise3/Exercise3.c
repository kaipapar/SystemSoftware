/*
File:			Exercise3.c
Author:			Karri Korsu
Description:	Answers to ex3
*/

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

int randNumGen();
void sumOfNums();
void sumOfEvens();
void operRandom();
void collatzSeq();
void fiboCheck();

int main() 
{
	
	sumOfNums(100);
	printf("\n===\n");
	sumOfEvens(-100);
	printf("\n===\n");
	operRandom();
	printf("\n===\n");
	collatzSeq();
	printf("\n===\n");
	fiboCheck();
	printf("\n===\n");/**/
	return 0;
}

/*	Task 3 a)	*/
void sumOfNums(int n) 
{
	// Sums all numbers together from 0 to function argument n.
	int finalSum = 0;

	for (int i = 0; i <= n; i++)
	{
		finalSum += i;
	}
	
	printf("The sum of all numbers from 0 to %d: %d\n",n, finalSum);
}

/*	Task 3 b)	*/
void sumOfEvens(int n) 
{
	//	Sums all even numbers together from 0 to function argument n.
	int finalSum = 0;

	for (int i = 0; i <= n; i++) 
	{
		if (i % 2 == 0) 
		{
			finalSum += i;
		}
	}

	printf("This is the sum of all even numbers from 0 to %d: %d\n", n, finalSum);
}

/*	Task 3 c)*/
void operRandom()
{	
	//	Multiplies a random number with itself until it reaches the maximun integer
	//	The computer is able to handle. 
	int randNum = randNumGen(2,20);

	printf("===\nRandom number between 2 and 20: %d\n" \
			, randNum);
			
	do
	{
		randNum *= randNum;
		if (randNum <= 0)
		{
			break;
		}
		
		printf(" %d\n", randNum);
	}
	while (randNum);
	
	printf("Integer upper limit %d reached.", INT_MAX);
}



/*	Task 4 b)*/
void collatzSeq() 
{
	// Creates a collatz sequence based on a random number
	int randNum = 13;//randNumGen(0,100);
	int collatz[300] = {0};

	printf("The random number generated: %d\n", randNum);

	if (randNum == 0)
	{
		printf("===\n0\n");
		
	} 
	else
	{
		//	The first element of the sequence is the random number itself.
		collatz[0] = randNum;

		for (int i = 0; collatz[i]>0; i++)
		{
			printf("\nCollatz element %d : %d", i, collatz[i]);
			
			if (collatz[i] == 1) 
			{
				break;
				
			}
			else if (collatz[i] % 2 == 0)
			{
				collatz[i+1] = collatz[i] / 2;
			}
			else 
			{
				collatz[i+1] = 3 * collatz[i] + 1;
				
			}
			
		}

	}
}



/*	Task 5b		*/
void fiboCheck()
{
	//	Checks whether a random number is in the fibonacci sequence.
	int randNum = 11;//randNumGen(0, 100000);
	//int randNum = 17711;
	int next = 1;
	int current = 0;
	int previous = 0;
	
	printf("The random number: %d", randNum);
	
	if (randNum == 0) 
	{
		printf("\nline 153 is not in the fibonacci sequence.");
		
	}
	else
	{
		while (current <= randNum)
		{
			//	Definition for fibonacci sequence:
			//	next_(n+1) = current_(n) + previous_(n-1)
			current = next;
			next = current + previous;
			previous = current;
			printf("\n %d", current);
			
			
		}
		if (current == randNum)
		{
				printf("\n is in the fibonacci sequence.");
		}
		else
		{
				printf("\n Line 171 is not in the fibonacci sequence.");
		}
	}
}

/*	Random number generator		*/
int randNumGen(int lower, int upper)
{
	time_t t = 0;
	
	srand((unsigned) time(&t));
	
	int randNum = rand() % (upper - lower + 1) + lower;
	
	return randNum;
}


