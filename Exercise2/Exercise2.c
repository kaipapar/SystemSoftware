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
	char num1Char;
	char num2Char;

	printf("Input an integer between 0 and 9: ");
	scanf("%c", &num1Char);
	printf("===\nInput another integer between 0 and 9: ");
	scanf(" %c", &num2Char);

	// checking whether user inputted characters can be interpreted
	// as integers using the ascii values for them
	if (48 > num1Char || num1Char > 57) 
	{
		printf("===\nPlease input 2 integers.\n");
	
	} else if (48 > num2Char || num2Char > 57) 
	{
		printf("===\nPlease input 2 integers.\n");
	
	} else 
	{	
		printf("===\nThe two integers you inputted are: %c and %c\n", num1Char, num2Char);
		
		if (num1Char == num2Char) 
		{
			printf("===\nAccording to our calculations the two integers you inputted are equal!\n");
			
		} else if (num1Char > num2Char) 
		{
			printf("===\nAccording to our calculations the first integer you inputted (%c)\
			\nis bigger than the second (%c)\n", num1Char, num2Char);
	
		} else 
		{
			printf("===\nAccording to our calculations the second integer you inputted (%c)\
			 \nis bigger than the first (%c)\n", num2Char, num1Char);
		}
		
		// converting inputted char numbers to type int for calculations
		int num1 = num1Char - '0';
		int num2 = num2Char - '0';
		
		int sumOfInt = num1 + num2;
		int differenceOf1st2nd = num1 - num2;
		int differenceOf2nd1st = num2 - num1;
		int productOfInt = num1 * num2;
		
		// converting integer to float to get decimal values.
		float averageOfInt = (num1*1.0 + num2*1.0) / 2;
		int powerOfInt = pow(num1, num2);

		printf("===\nSum of two integers: %d\n",sumOfInt);
		printf("===\nDifference of the first and second integer: %d\n", differenceOf1st2nd);
		printf("===\nDifference of the second and first integer: %d\n", differenceOf2nd1st);
		printf("===\nProduct of two integers: %d\n", productOfInt);
		printf("===\nAverage of two integers: %.2f\n", averageOfInt);
		printf("===\nFirst integer raised to the power of the second: %d\n", powerOfInt);
		
		//checking whether division of the integers is possible by checking is either of the integers 0
		if (num1 == 0 || num2 == 0) 
		{
			if (num1 == num2) 
			{
				printf("===\nBoth numbers are 0, they can't be divided.\n");

			} else if (num1 == 0) 
			{
				printf("===\nThe first integer is 0, therefore in divisions between the two integers  \
				\nthe first one cannot be the denominator and when it is the numerator \
				\nthe division equals to 0.\n");
			} else if (num2 == 0) 
			{
				printf("===\nThe second integer is 0, therefore in divisions between the two integers \
				 \nthe second one cannot be the denominator and when it is the numerator\
				  \nthe division equals to 0.\n");			
			}
		}else 
		{
			float divisionOf1st2nd = (num1*1.0) / (num2*1.0);
			float divisionOf2nd1st = (num2*1.0) / (num1*1.0);
			
			printf("===\nDivision between the first and second integer: %.2f\n", divisionOf1st2nd);
			printf("===\nDivision between the second and first integer: %.2f\n", divisionOf2nd1st);
		}
	}
	
/* Task 5 */

	// Initializing random number generator
	time_t t;
	srand((unsigned) time(&t));
	
	int rand_num;
	
	// Assigns random integer to rand_num
	printf("===\nRandom number between 0 and 100: %d\n" \
			, rand_num = rand() % 100);
	
	
	if (rand_num == 0) 
	{
		printf("===\nThe random number is neither odd nor even; it is zero!\n");
	
	} else if (rand_num % 2 == 0) 
	{
		printf("===\nThe random number is even.\n");
	
	} else 
	{
		printf("===\nThe random number is odd.\n");
		
	}
	
	if (rand_num % 4 == 0 && rand_num % 7 == 0) 
	{
		printf("===\nThe random number is divisible by 4 and 7\n");
	
	} else 
	{
		printf("===\nThe random number is not divisible by 4 and 7\n");
		
	}

/* Task 6 */
	
	int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;
	int n = 0;
	int num_check = 0;
		
	// Two for loops to print int_array in correct and reverse order
	printf("===\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", int_array[i]);
		n++;
		
		if (rand_num == int_array[i]) 
		{
			num_check = 1;
			
		}
		
		if (n == 10)
		{
			printf("===\n");
			
		}
	}
	
	for (i = 9; i >= 0; i--)
	{
		printf("%d\n", int_array[i]);
		n++;
		
	}
	if (num_check) 
	{
		printf("===\nThe random number (%d) is in the array!\n", rand_num);
		
	} else
	{
		printf("===\nThe random number (%d) is not in the array!\n", rand_num);
	}
	
	
	return 0;
}


