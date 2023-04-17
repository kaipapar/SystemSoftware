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

int getNumOfStudents()
{
	printf("How many students would you like to add?\n");
	char *size = readUserInput();
	int intSize = 0;
	
	if (checkUserInputSize(size) == 1)
	{
		intSize = atoi(size);

	}
	else 
	{
		printf("Invalid input \n");
	}
	
	return intSize;
}

void askToFillStruct(int size, struct Student *pointer)
{
	printf("Press 0 if you want to input students yourself or 1 if you want them read from a file:\n");
	
	char *input = readUserInput();
	int intInput = atoi(input);

	switch (intInput)
	{
		case 0:
		fillStructFromFile(size, pointer);

//		fillStruct(size, pointer);
//		printStruct(size, pointer);
		printStructFile(size, pointer);

		break;
		
		case 1:
//		fillStructFromFile(size, pointer);
		printStructFile(size, pointer);
		break;
		
		default:
		printf("Invalid input!\n");
	}
}

void fillStructFromFile(int size, struct Student *pointer)
{
	FILE *filePointer =  NULL;
	filePointer = fopen("Student.txt", "w");
	
	if (filePointer == NULL)
	{
		fprintf(stderr, "\n Error opening file \n");
		exit(1);
		
	}
	struct Student *write_struct = malloc(size * sizeof(struct Student));
  
	for (int i = 0; i < size; i++)
	{
		printf("Enter student Name: \n");
		char* arrayStudentName = readUserInput();
		if (checkUserInputName(arrayStudentName) == 1)
		{
			strncpy((write_struct + i )->studentName, arrayStudentName, ARRAYSIZE);    
		}
		else
		{
			printf("Invalid name.\n");
		}
		
		printf("Enter student ID: \n");
		char* arrayStudentID = readUserInput();
		if (checkUserInputID(arrayStudentID) == 1)
		{
			//write_struct->studentID = atoi(arrayStudentID);
			(write_struct + i )->studentID = atoi(arrayStudentID);
		}
		
		printf("Enter student GPA: \n");
		char* arrayStudentGPA = readUserInput();
		if (checkUserInputGPA(arrayStudentGPA) == 1)
		{
			// write_struct->studentGPA = atof(arrayStudentGPA);
			(write_struct + i )->studentGPA = atof(arrayStudentGPA);
		}
	
	}
	// writing to file
   	if (fwrite(&write_struct, sizeof(write_struct), 1, filePointer))
	{
		printf("Success\n");
	}
	
    
    // setting pointer to start of the file
    //rewind(filePointer);

    // close file
    fclose(filePointer);
	free(write_struct);
}

void printStructFile(int size, struct Student *pointer)
{
	FILE *filePointer = NULL;
	filePointer = fopen("Student.txt", "r");
	if (filePointer == NULL)
	{
		fprintf(stderr, "\n Error opening file\n");
		exit(1);
	}


//	struct Student read_struct[1] = {0};
	//struct Student *read_struct = malloc(size * sizeof(struct Student));
	char readBuffer[100] = " ";

	printf("Hello 371 \n");
	// this doesn't work
	//int i = 0;

	//fread(&read_struct, sizeof(read_struct), 1, filePointer) == 1
	// try fgets
	fgets(readBuffer, 100, filePointer);
	//while (fgets(readBuffer, sizeof(readBuffer),filePointer) != NULL)
	//while (fread(&read_struct[i], sizeof(struct Student), 1, filePointer) == 1)
	/*
    	printf("Name: %s \t ID: %d \tGPA: %.2f\n", (read_struct + i)->studentName,
           (read_struct + i)->studentID, (read_struct + i)->studentGPA);	
		printf("Hello 376\n");*/

		printf("Hello 376\n");
		printf("Name: ID: GPA: \n %s \n", readBuffer);

	
	fclose(filePointer);
}
