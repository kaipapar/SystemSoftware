/*
File:			scanf_ex	
Author:			Karri Korsu
Description:	read 2 int from user one by one and print them.
*/

#include <stdio.h>

int main() {

	char num1;
	char num2;

	printf("Input an integer: ");
	scanf("%c", &num1);
	printf("===\nInput another integer: ");
	scanf(" %c", &num2);
	
	if (48 > num1 || num1 > 57) 
	{
		printf("===\nPlease input 2 integers.\n");
	
	} else if (48 > num2 || num2 > 57) 
	{
		printf("===\nPlease input 2 integers.\n");
	
	} else 
	{
		printf("===\nThe two integers you inputted are: %c and %c\n", num1, num2);
		
		if (num1 == num2) 
		{
			printf("===\nAccording to our calculations the two integers you inputted are equal!\n");
			
		} else if (num1 > num2) 
		{
			printf("===\nAccording to our calculations the first integer you inputted (%c) is bigger than the second (%c)\n", num1, num2);
	
		} else 
		{
			printf("===\nAccording to our calculations the second integer you inputted (%c) is bigger than the first (%c)\n", num2, num1);
		}
	}
	
	return 0;
}

//use an if 
