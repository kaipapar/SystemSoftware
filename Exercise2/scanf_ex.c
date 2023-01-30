/*
File:			scanf_ex	
Author:			Karri Korsu
Description:	read 2 int from user one by one and 
				print them in various vays.
*/

#include <math.h>
#include <stdio.h>


int main() {
	//initializing number variables as type char for error checking
	char num1Char;
	char num2Char;

	printf("Input an integer: ");
	scanf("%c", &num1Char);
	printf("===\nInput another integer: ");
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
	{	// checking complete: printing evaulations of the two integers still using their ascii values 
		printf("===\nThe two integers you inputted are: %c and %c\n", num1Char, num2Char);
		
		if (num1Char == num2Char) 
		{
			printf("===\nAccording to our calculations the two integers you inputted are equal!\n");
			
		} else if (num1Char > num2Char) 
		{
			printf("===\nAccording to our calculations the first integer you inputted (%c)\
			 is bigger than the second (%c)\n", num1Char, num2Char);
	
		} else 
		{
			printf("===\nAccording to our calculations the second integer you inputted (%c)\
			 is bigger than the first (%c)\n", num2Char, num1Char);
		}
		
		// converting inputted char numbers to type int for calculations
		// to achieve the integer value of the char we must subtract 
		// the ascii value of '0' from the ascii value of the inputted number.
		int num1 = num1Char - '0';
		int num2 = num2Char - '0';
		
		int sumOfInt = num1 + num2;
		int differenceOf1st2nd = num1 - num2;
		int differenceOf2nd1st = num2 - num1;
		int productOfInt = num1 * num2;
		
		// converting integer to float by multiplying integer value of a number by the float value 1.0.
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
	
	return 0;
}

