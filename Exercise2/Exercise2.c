/*
File:			Exercise2.c	
Author:			Karri Korsu
Description:	Answers of SysSoftware Ex2
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
/* Task 4 */
	
	//initializing number variables as type char for error checking
	char num1Str[10];
	char num2Str[10];

	printf("Input an integer: ");
	scanf("%s", &num1Str);
	printf("===\nInput another integer: ");
	scanf(" %s", &num2Str);
	
	// atoi() function converts str into int
	int num1Int = atoi(num1Str);
	int num2Int = atoi(num2Str);

	// checking whether user inputted characters can be interpreted
	// as integers using the ascii values for them
	if (48 > num1Str[0] || num1Str[0] > 57) 
	{
		printf("===\nPlease input 2 integers.\n");
	
	} else if (48 > num2Str[0] || num2Str[0] > 57) 
	{
		printf("===\nPlease input 2 integers.\n");
	
	} else 
	{	
		printf("===\nThe two integers you inputted are: %d and %d\n", num1Int, num2Int);
		
		if (num1Int == num2Int) 
		{
			printf("===\nAccording to our calculations the two integers you inputted are equal!\n");
			
		} else if (num1Int > num2Int) 
		{
			printf("===\nAccording to our calculations the first integer you inputted (%s)\
			\nis bigger than the second (%s)\n", num1Str, num2Str);
	
		} else 
		{
			printf("===\nAccording to our calculations the second integer you inputted (%d)\
			 \nis bigger than the first (%d)\n", num2Int, num1Int);
		}
				
		int sumOfInt = num1Int + num2Int;
		int differenceOf1st2nd = num1Int - num2Int;
		int differenceOf2nd1st = num2Int - num1Int;
		int productOfInt = num1Int * num2Int;
		
		// converting integer to float to get decimal values.
		float averageOfInt = (num1Int*1.0 + num2Int*1.0) / 2;
		int powerOfInt = pow(num1Int, num2Int);

		printf("===\nSum of two integers: %d\n",sumOfInt);
		printf("===\nDifference of the first and second integer: %d\n", differenceOf1st2nd);
		printf("===\nDifference of the second and first integer: %d\n", differenceOf2nd1st);
		printf("===\nProduct of two integers: %d\n", productOfInt);
		printf("===\nAverage of two integers: %.2f\n", averageOfInt);
		printf("===\nFirst integer raised to the power of the second: %d\n", powerOfInt);
		
		//checking whether division of the integers is possible by checking is either of the integers 0
		if (num1Int == 0 || num2Int == 0) 
		{
			if (num1Int == num2Int) 
			{
				printf("===\nBoth numbers are 0, they can't be divided.\n");

			} else if (num1Int == 0) 
			{
				printf("===\nThe first integer is 0, therefore in divisions between the two integers  \
				\nthe first one cannot be the denominator and when it is the numerator \
				\nthe division equals to 0.\n");
			} else if (num2Int == 0) 
			{
				printf("===\nThe second integer is 0, therefore in divisions between the two integers \
				 \nthe second one cannot be the denominator and when it is the numerator\
				  \nthe division equals to 0.\n");			
			}
		}else 
		{
			float divisionOf1st2nd = (num1Int*1.0) / (num2Int*1.0);
			float divisionOf2nd1st = (num2Int*1.0) / (num1Int*1.0);
			
			printf("===\nDivision between the first and second integer: %.2f\n", divisionOf1st2nd);
			printf("===\nDivision between the second and first integer: %.2f\n", divisionOf2nd1st);
		}
	}
	
/* Task 5 */

	// Initializing random number generator
	time_t t;
	srand((unsigned) time(&t));
	
	int randNum;
	
	// Assigns random integer to randNum
	printf("===\nRandom number between 0 and 100: %d\n" \
			, randNum = rand() % 100);
	
	
	if (randNum == 0) 
	{
		printf("===\nThe random number is neither odd nor even; it is zero!\n");
	
	} else if (randNum % 2 == 0) 
	{
		printf("===\nThe random number is even.\n");
	
	} else 
	{
		printf("===\nThe random number is odd.\n");
		
	}
	
	if (randNum % 4 == 0 && randNum % 7 == 0) 
	{
		printf("===\nThe random number is divisible by 4 and 7\n");
	
	} else 
	{
		printf("===\nThe random number is not divisible by 4 and 7\n");
		
	}

/* Task 6 */
	
	int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;
	int n = 0;
	int numCheck = 0;
		
	// Two for loops to print intArray in correct and reverse order
	printf("===\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", intArray[i]);
		n++;
		
		if (randNum == intArray[i]) 
		{
			numCheck = 1;
			
		}
		
		if (n == 10)
		{
			printf("===\n");
			
		}
	}
	
	for (i = 9; i >= 0; i--)
	{
		printf("%d\n", intArray[i]);
		n++;
		
	}
	if (numCheck) 
	{
		printf("===\nThe random number (%d) is in the array!\n", randNum);
		
	} else
	{
		printf("===\nThe random number (%d) is not in the array!\n", randNum);
	}
	
	
	return 0;
}


