/*
File:			mainParameters.c	
Author:			Karri Korsu
Description:	Main functions parameters
*/

#include <stdio.h>

// Main function has either 0 or 2 parameters
// int argc (argument count) and char *argv[] (argument vector).

int main(int argc, char *argv[]) 
{
	// Argument count tells the amount of arguments given
	// it includes the ./run command.
	printf("How many arguments: %d\n",argc);	
	
	// lets print out every argument:
	for (int i = 1; i < argc; i++) 
	{
		printf("This is your argument in slot [%d]: %s\n.", i, argv[i]);
	}
	
	//lets try to access an arguments first character
	printf("Should be first arguments first character:%c\n", argv[1][0]);
	
	return 0;
}
