/*
File:			Student.c
Author:			Karri Korsu
Description:	Execution code for Ex8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
struct Student * createStructArray(int size)
{

	struct Student *studentArrayPtr = NULL;

	
	studentArrayPtr = (struct Student *)malloc(sizeof(struct Student) * size);

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

/*	Takes input - error checks inputs - assigns inputs to struct	*/
void fillStruct(int size, struct Student *pointer)
{
	for (int i = 0; i < size; i++)
	{
		printf("Enter student Name: \n");
		char* arrayStudentName = readUserInput();
		if (checkUserInputName(arrayStudentName) == 1)
		{
			strncpy((pointer+i)->studentName, arrayStudentName, ARRAYSIZE);
		}
		else
		{
			printf("Invalid name.\n");
		}
		
		
		printf("Enter student ID: \n");
		char* arrayStudentID = readUserInput();
		if (checkUserInputID(arrayStudentID) == 1)
		{
			(pointer + i)->studentID = atoi(arrayStudentID);
		}
		
		
		printf("Enter student GPA: \n");
		char* arrayStudentGPA = readUserInput();
		if (checkUserInputGPA(arrayStudentGPA) == 1)
		{
			(pointer + i)->studentGPA = atof(arrayStudentGPA);
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

int checkUserInputName(char* userInput)
{
// a-z = 97 - 122
// A-Z = 65 - 90
// - = 45

	int flag = 2;
	if ((userInput[0] >= 65 && userInput[0] <= 90) 
		|| (userInput[0] >= 97 && userInput[0] <= 122))
	{	
//	note this wont work on integers with more than 10 digits
		for (int i = 1; i < ARRAYSIZE; i++)	
		{
			if ((userInput[0] >= 65 && userInput[0] <= 90) || (userInput[0] >= 97 
				&& userInput[0] <= 122) || userInput[i] == 45)
			{	// if the element is a letter: advance.
				flag = 1;
			}
			else if (userInput[i] == 0)
			{					
				// if the element isnt a letter 
				flag = 1;
			}
			else if (userInput[i] == 32 && userInput[i+1] == 32)
			{
				flag = 0;
				break;
			}
			else if (userInput[i] == 32)
			{
				flag = 1;
			}
			
		}
	}
	else
	{
		flag = 0;
	}
	return flag;
}

int checkUserInputGPA(char* userInput)
{
// . = 46
	int flag = 2;
	int dotCheck = 1; //	check if dot is used or not
	if (userInput[0] >= 48 && userInput[0] <= 57)
	{	
	//	note this wont work on integers with more than 10 digits
		for (int i = 1; i < ARRAYSIZE; i++)	
		{
			if (userInput[i] >= 48 && userInput[i] <= 57 )
			{	// if the element is a number: advance.
				flag = 1;
			}
			else if (userInput[i] == 46)
			{
				dotCheck--;
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
					dotCheck--;
					break;
				}
			}
		}
	}
	else
	{
		flag = 0;
	}
	if (dotCheck < 0)	//	if the dot is used more than once
	{
		flag = 0;
	}
	return flag;
}

int checkUserInputSize(char* userInput)
{	//	if the first element is a dash or a number
	int flag = 2;
	if (userInput[0] >= 48 && userInput[0] <= 57)
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
				flag = 0;
				break;
			}
		}
	}
	else
	{
		flag = 0;
	}
	return flag;
}

int getNumOfStudents()
{
	int size = -1;
	while (checkUserInputSize(size) == 0);
	{
		printf("How many students would you like to have?\n");
		size = readUserInput();
	}
	return size;
}

void askToFillStruct(int size, struct Student *pointer)
{
	printf("Press 0 if you want to input students yourself or 1 if you want them read from a file:\n");
	
	char *input = readUserInput();
	
	switch (input)
	{
		case 48:
		fillStruct(size, pointer);
		break;
		
		case 49:
		fillStructFromFile(size, pointer);
		break;
		
		default:
		printf("Invalid input!\n");
	}

}

void fillStructFromFile(int size, struct Student *pointer)
{
	FILE *filepointer =  NULL;
	filepointer = fopen("Student.txt", "r");
	
	//fscanf(reads,"%d %d %d %d %lf", &n->id, &n->sign, &n->year, &n->month, &n->amount);
	
	
	fclose(filepointer);
}
