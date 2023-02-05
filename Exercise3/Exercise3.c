/*
File:			Exercise3.c
Author:			Karri Korsu
Description:	Answers to ex3
*/

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

void sumOfNums();
void sumOfEvens();
void operRandom();

int main() 
{
	
	
	sumOfNums(10);
	printf("\n===\n");
	sumOfEvens(10);
	printf("\n===\n");
	operRandom();
	printf("\n===\n");
	
	return 0;
}

/*	Task 3 a)	*/
void sumOfNums(int n) 
{
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		num += i;
		printf("%d\n",num);
	}
	printf("%d\n",num);
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
			printf("%d\n",num);
		}
	}
	printf("%d\n",num);
}

/*	Task 3 c)*/
void operRandom()
{
	time_t t = 0;
	
	srand((unsigned) time(&t));
	
	int randNum = rand() % (20 - 2 + 1) + 2;
	//int randNum = 20;
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




