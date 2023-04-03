/*
File:			Student.c
Author:			Karri Korsu
Description:	Execution code for Ex8
*/

#include <stdio.h>
#include <stdlib.h>

#include "Student.h"

void testStudent()
{
	printf("Hello, student!\n");
}

struct Student 
{
	char studentName[30];
	unsigned int studentID;
	float studentGPA;
};

//	Create a dynamic array of structs
struct Student * createStructArray()
{

	struct Student *studentArrayPtr = NULL;
	int numberOfStudents = 5;
	
	studentArrayPtr = (struct Student *)malloc(sizeof(struct Student) * numberOfStudents);

	if (studentArrayPtr == NULL)
	{
		printf("Dynamic memory allocation failed!\n");
		studentArrayPtr = 0;
	}

	return studentArrayPtr;	
}

void printStruct(int size, struct Student *pointer)
{
	for (int i = 0; i < size; i++)
	{
		printf("Name: %s \t ID: %d \t GPA: %f\n", (pointer + i)->studentName, (pointer + i)->studentID, (pointer + i)->studentGPA);
	}
}

void fillStruct(int size, struct Student *pointer)
{
	//	error check all fields...
	char charStudentName[30] = 'a';
	int intStudentID = 0;
	float floatStudentGPA = 0.0;
	
	for (int i = 0; i < size; i++)
	{
		printf("Enter student Name: \n");
		char* arrayStudentName = readUserInput();
		if (checkUserInputName(arrayStudentName) == 1)
		{
			charStudentName = arrayStudentName;
			(pointer + i)->studentName = charStudentName
		}
		
			
		printf("Enter student ID: \n");
		char* arrayStudentID = readUserInput();
		if (checkUserInputID(arrayStudentID) == 1)
		{
			studentID = atoi(arrayStudentID);
		}
		
		printf("Enter student GPA: \n");
		char* arrayStudentGPA = readUserInput();
		if (checkUserInputGPA(arrayStudentGPA) == 1)
		{
			studentGPA = atof(arrayStudentGPA);
		}
		
	}
}

/*	Asks for user input and returns that input as char array	*/
char* readUserInput()
{
	char *array = (char*) malloc(ARRAYSIZE * sizeof(char*));
	//printf("Enter a positive integer: \n");
	scanf(" %s", array);

	return array;
}

/*	Checks whether userInput char array can be interpreted as integer
	returns 0 == False, 1 == True	*/
int checkUserInputID(char* userInput)
{	//	if the first element is a dash or a number
	int flag = 2;
	if (userInput[0] == 45 || (userInput[0] >= 48 && userInput[0] <= 57))
	{	
//	note this wont work on integers with more than 10 digits
		for (int i = 1; i < ARRAYSIZE; i++)	
		{
			if (userInput[i] >= 48 && userInput[i] <= 57)
			{	// if the element is a number: advance.
				flag = 1;
			}
			else 
			{					
				// if the element isnt a number 
				// for elements in userInput from i to end of array.
				if (userInput[i] == 0)
				{	// if the element is empty: advance.
					flag = 1;
				}
				else if (userInput[i] == 46 || userInput[i] == 45)
				{	// if its something else than empty the input is invalid.
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
	return flag;
}

