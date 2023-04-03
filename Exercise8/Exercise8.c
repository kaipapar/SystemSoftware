/*
File:			Exercise8.c
Author:			Karri Korsu
Description:	Execution code for Ex8
*/

#include <stdio.h>

#include "Student.c"
#include "Student.h"

int main() 
{
	testStudent();
	printf("Hello!\n");
	
	struct Student *ptr = createStructArray();
	printf("Helloloo\n");
	
	printStruct(5, ptr);


	free(ptr);
	
	return 0;
}
