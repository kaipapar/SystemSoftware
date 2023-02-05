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
	sumOfEvens(100);
	printf("\n===\n");
	/*operRandom();
	printf("\n===\n");
	collatzSeq();
	printf("\n===\n");
	fiboCheck();
	printf("\n===\n");*/
	return 0;
}

/*	Task 3 a)	*/
void sumOfNums(int n) 
{
	int finalSum = 0;
	for (int i = 0; i <= n; i++)
	{
		finalSum += i;
		//printf("%d\n",finalSum);
	}
	
	printf("The sum of all numbers from 0 to %d: %d\n",n, finalSum);
}

/*	Task 3 b)	*/
void sumOfEvens(int n) 
{
	int num = 0;
	for (int i = 0; i <= n; i++) 
	{
		if (i % 2 == 0) 
		{
			num += i;
			printf("line57%d\n",num);
		}
		printf("line59%d\n",num)
	}
	printf("%d\n",num);
}

/*	Task 3 c)*/
void operRandom()
{	
	int randNum = randNumGen(2,20);
	// Assigns random integer to randNum
	printf("===\nRandom number between 2 and 20: %d\n" \
			, randNum);
			
	int randNum_multip = randNum;
	
	do
	{
		randNum_multip *= randNum_multip;
		if (INT_MIN <= randNum_multip && randNum_multip <= 0)
		{
			//printf("Line 76:%d\n", randNum_multip*randNum_multip);
			break;
		}
		
		printf("Line 80: %d\n", randNum_multip);
	}
	while (randNum_multip); //INT_MAX
	printf("Integer upper limit reached: %d", INT_MAX);
}



/*	Task 4 b)*/
void collatzSeq() 
{
	int randNum = randNumGen(0,100);
	
	if (randNum == 0)
	{
		printf("===\n0\n");
		
	} 
	else
	{
		int collatz[300] = {0};
		collatz[0] = randNum;
		collatz[0] = 54;
		
		for (int i = 0; collatz[i]>0; i++)
		{
			printf("\n%d", collatz[i]);
			
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
	int randNum = randNumGen(0, 100000);
	//int randNum = 17711;
	int current = 1;
	int previous = 0;
	int prevprevious = 0;
	
	printf("The random number: %d", randNum);
	
	if (randNum == 0) 
	{
		printf("\nline 153 is not in the fibonacci sequence.");
		
	}
	else
	{
		while (current <= randNum)
		{
			previous = current;
			current = previous + prevprevious;
			prevprevious = previous;
			printf("\n Line 163: %d", current);
			
			
		}
		if (previous == randNum)
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


