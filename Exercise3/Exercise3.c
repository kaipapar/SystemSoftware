/*
File:			Exercise3.c
Author:			Karri Korsu
Description:	Answers to ex3
*/

#include <stdio.h>

void sumOfNums();
void sumOfEvens();
void operRandom();

int main() 
{
	
	
	sumOfNums(10);
	sumOfEvens(10);
	operRandom();
	
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

