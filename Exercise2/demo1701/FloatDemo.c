/*
File:			FloatDemo.c
Author:			Sanna Määttä
Description:	Float rounding demo
*/

#include <stdio.h>

float division(int num1, int num2);

int main() {

	int number1 = 18;
	int number2 = 7;
	
	//printf("Division 18/7 should be 2.6.\n");
	//printf("division of %d and %d is: %.1f}n", number1, number2, division(number1, number2));
	
	printf("Division 13 / 4 should be 3.3... but is not... Why not? \n");
	printf("Division of %d and %d is: %.1f\n", number1, number2, division(number1, number2));
	return 0;
}

//With floating point numbers you have to be careful. Despite two floats being displayed similarly they can be dissimilar
