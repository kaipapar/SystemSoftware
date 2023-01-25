/*
File:			scanf_ex	
Author:			Karri Korsu
Description:	read 2 int from user one by one and print them.
*/

#include <math.h>
#include <stdio.h>


int main() {

	char num1Char;
	char num2Char;

	printf("Input an integer: ");
	scanf("%c", &num1Char);
	printf("===\nInput another integer: ");
	scanf(" %c", &num2Char);

	
	if (48 > num1Char || num1Char > 57) 
	{
		printf("===\n1Please input 2 integers.\n");
	
	} else if (48 > num2Char || num2Char > 57) 
	{
		printf("===\n2Please input 2 integers.\n");
	
	} else 
	{
		printf("===\nThe two integers you inputted are: %c and %c\n", num1Char, num2Char);
		
		if (num1Char == num2Char) 
		{
			printf("===\nAccording to our calculations the two integers you inputted are equal!\n");
			
		} else if (num1Char > num2Char) 
		{
			printf("===\nAccording to our calculations the first integer you inputted (%c) is bigger than the second (%c)\n", num1Char, num2Char);
	
		} else 
		{
			printf("===\nAccording to our calculations the second integer you inputted (%c) is bigger than the first (%c)\n", num2Char, num1Char);
		}
		

		int num1 = num1Char - '0';
		int num2 = num2Char - '0';
		
		int sumOfInt = num1 + num2;
		int differenceOf1st2nd = num1 - num2;
		int differenceOf2nd1st = num2 - num1;
		int productOfInt = num1 * num2;
		float averageOfInt = (num1*1.0 + num2*1.0) / 2;
		int powerOfInt = round(pow(num1, num2));
		//int powerOfInt = (int)(pow(num1, num2) + 1e-9);
		printf("===\nSum of two integers: %d\n",sumOfInt);
		printf("===\nDifference of the first and second integer: %d\n", differenceOf1st2nd);
		printf("===\nDifference of the second and first integer: %d\n", differenceOf2nd1st);
		printf("===\nProduct of two integers: %d\n", productOfInt);
		printf("===\nAverage of two integers: %.2f\n", averageOfInt);
		printf("===\nFirst integer raised to the power of the second: %d\n", powerOfInt);
		
		if (num1 == 0 || num2 == 0) 
		{
			if (num1 == num2) 
			{
				printf("===\nBoth numbers are 0, they can't be divided.\n");

			} else if (num1 == 0) 
			{
				printf("===\nThe first integer is 0, therefore in divisions between the two integers \nthe first one cannot be the denominator and when it is the numerator \nthe division equals to 0.\n");
			} else if (num2 == 0) 
			{
				printf("===\nThe second integer is 0, therefore in divisions between the two integers \nthe second one cannot be the denominator and when it is the numerator \nthe division equals to 0.\n");			
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


