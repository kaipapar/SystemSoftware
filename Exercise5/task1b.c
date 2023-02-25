/*
File:			task1b.c
Author:			Karri Korsu
Description:	
				This code takes a user specified amount of floats as an 
				input into an array and prints the biggest float 
				inputted.

*/

#include <stdio.h>

int main () 
{
	int i;
	int n;
	float arr[100] = {0};

	printf("Enter total number of elements (1 to 100): ");
	scanf("%d", &n);
	printf("\n");
	
	for (i = 0; i < n; i++)
	{
		printf("Enter number %d: ", i);
		scanf("%f", &arr[i]);
	
		if (arr[0] < arr[i])
		{
			arr[0] = arr[i];
		}		
	}
	
	printf("What am I printing out? %2.f", arr[0]);
	
	
	return 0;
}
