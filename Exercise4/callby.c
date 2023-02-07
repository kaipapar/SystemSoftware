/*
File:
Author:
Description:
*/



#include <stdio.h>
/*	Call by value */

void callByValue(int x, int y)
{
	
	x = x+y;
	y = x+y;
	
	printf("first var from function: %d, second var from function: %d \n", x, y);
}


/*	Call by reference */

void callByReference(int* x, int* y)
{
	
	*x = *x + *y;
	*y = *x + *y;
	
	printf("first var from function: %d, second var from function: %d \n", *x, *y);
}

int main() 
{
	int a = 3;
	int b = 5;
	int c = 7;
	int d = 9;
	
	callByValue(a, b);
	printf("first var: %d, second var: %d\n", a, b);
	callByReference(&c, &d);
	printf("first var: %d, second var: %d\n", c, d);


	return 0;
}
