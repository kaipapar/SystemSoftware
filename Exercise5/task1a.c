/*
File:			task1a.c
Author:			Karri Korsu
Description:	
				This code asks for integer input to variable num 
				and while variable count is less than num it adds 
				variables x y and z together, incrementing count by 1 
				each cycle
*/
#include <stdio.h>

int main () 
{
	int num = 0;
	int x = 0;
	int y = 1;
	int z = 2;
	int new_variable = 0;
	int	count = 3;
	
//	ask user input
	printf("Enter a number: \t");
	scanf("%d", &num);
	printf("Original set of numbers: %d \t %d \t %d \t", x, y, z);
	
//	while count is less than the user inputted number 
//	the program sums x,y and z together.
//	in further loops z stores the value of the sum.
	while (count < num)
	{
		new_variable = x + y + z;
		printf("%d \n", new_variable);
		x = y;
		y = z;
		z = new_variable;
		count = count + 1;
	}
	return 0;
}
