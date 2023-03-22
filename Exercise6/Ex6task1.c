/*
File:			Ex6task1.c
Author:			Karri Korsu
Description:	Answers to Exercise 6 task 1abc
*/

#include <stdio.h>

int main () 
{
	int int_var = 5;
	char char_var = 'a';
	float float_var = 7.3;
	
	printf("\n int_var: %d \t char_var: %c \t float_var: %f \n", int_var, char_var, float_var);
	
	int *int_pointer = NULL;
	char *char_pointer = NULL;
	float *float_pointer = NULL;
	
	int_pointer = &int_var;
	char_pointer = &char_var;
	float_pointer = &float_var;
	
	printf("\n int_pointer: %p \t char_pointer: %p \t float_pointer: %p \n", int_pointer, char_pointer, float_pointer);

	printf("\n int_pointer_content: %d \t char_pointer_content: %c \t float_pointer_content: %f \n", *int_pointer, *char_pointer, *float_pointer);
	return 0;
}
