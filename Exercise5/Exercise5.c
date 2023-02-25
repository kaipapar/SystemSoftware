	/*
File:			Exercise5.c
Author:			Karri Korsu
Description:	Answers to tasks 3 and 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000000
#define MIN 0


int main (int argc, char *argv[]) 
{
	int i = 0;
	int flag = 0;
	int arglen = strlen(argv[1]);
	
	printf("Arguments: %d\n", argc);
	printf("Arg 1 : %s\n", argv[1]);

	
	
	if (arglen <= 7)
	{
		if (argv[1][0] == 45 || (argv[1][0] >= 48 && argv[1][0] <= 57))
		{	
			for (i = 1; i < arglen; i++)
			{
				if (argv[1][i] >= 48 && argv[1][i] <= 57)
				{	// if the element is a number: advance.
					flag = 1;
				}
				else 
				{					
					flag = 0;
					break;
				}
			}
		}
	}
	
	else 
	{
		flag = 0;
	}
	
	if (flag == 1)
	{
		printf("This is your argument: %s \n", argv[1]);
	}
	else
	{
		printf("Argument is not valid.\n");
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
	
	// cycle through the argument to check if all characters are numbers 
	// or use some magic to do it
	return 0;
}
