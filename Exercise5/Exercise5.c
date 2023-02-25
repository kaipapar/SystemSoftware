/*
File:			Exercise5.c
Author:			Karri Korsu
Description:	Answers to tasks 3 and 4
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000
#define MIN 0


int main (int argc, char *argv[]) 
{
	int i = 0;


	printf("Arguments: %d\n", argc);
	printf("Arg 1 : %s\n", argv[1]);
	
	if (argv[1][0] == "-")
	{
		i = 1;
		
	}

	for (i; )
	{
	
	}

	int argv1 = atoi(argv[1]);
	
	if (argc == 2 && argv1 < MAX && MIN < argv1)
	{
		
		printf("%s", argv[1]);
	
	} else
	{
		printf("Your arguments are too many, too few or not between 10000000 and 0.\n");
		printf("Argument count: %d\n", argc - 1);
	}
	
	
	return 0;
}
