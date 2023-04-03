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


	int size = getNumOfStudents();
	struct Student *ptr = createStructArray(size);
	printf("Helloloo\n");
	

	printStruct(size, ptr);
	askToFillStruct(size, ptr);
	printStruct(size, ptr);
	


	free(ptr);
	
	return 0;
}
