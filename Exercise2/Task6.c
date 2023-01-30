/*
File: 			Task6.c
Author:			Karri Korsu
Description:	Print 10 integers front to back and back to front
*/

#include <stdio.h>

int main () {
	int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;
	int n = 0;
		
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", int_array[i]);
		n++;
		if (n == 10)
	{
		printf("===\n");
		break;
	}
	}
	for (i = 9; i >= 0; i--)
	{
		printf("%d\n", int_array[i]);
		n++;
		if (n == 20)
	{
		printf("===\n");
		break;
	}
	}
	
	


	return 0;
}
