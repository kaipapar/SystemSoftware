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

void fillStruct(int oldSize, int newSize, struct Student *pointer)
{
	
	for (int i = oldSize; i < newSize; i++)
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
		int flag = 0;
		if (checkUserInputID(arrayStudentID) == 1)
		{
			for (int i = oldSize; i < newSize; i++)
			{
				if ((pointer+i)->studentID == atoi(arrayStudentID))
				{
					printf("Student ID collision! \n");
					flag = 0;
					break;
				}
				else
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				(pointer + i)->studentID = atoi(arrayStudentID);

			}
		}
		else
		{
			printf("Invalid student ID. \n");
		}
		
		printf("Enter student GPA: \n");
		char* arrayStudentGPA = readUserInput();
		if (checkUserInputGPA(arrayStudentGPA) == 1)
		{
			(pointer + i)->studentGPA = atof(arrayStudentGPA);
		}
		else
		{
			printf("Invalid student GPA. \n");
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



/*	Check that argument is positive integer and 6 digits.*/
int checkUserInputID(char* userInput)
{	//	if the first element is a dash or a number
	int flag = 2;
	if ((userInput[0] == 45 || (userInput[0] >= 48 && userInput[0] <= 57)) && strlen(userInput) == 6)
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

/*	Check that student name contains letters, one(if any) hyphen and is less than 30 characters.	*/
int checkUserInputName(char* userInput)
{
// a-z = 97 - 122
// A-Z = 65 - 90
// - = 45

	int flag = 2;
	if (((userInput[0] >= 65 && userInput[0] <= 90) 
		|| (userInput[0] >= 97 && userInput[0] <= 122))
		&& strlen(userInput) < 30)
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
/*	Checks that argument is a float between 0 and 5*/
int checkUserInputGPA(char* userInput)
{
// . = 46
	int flag = 2;
	int dotCheck = 1; //	check if dot is used or not
	if (userInput[0] >= 48 && userInput[0] <= 57 && atof(userInput) <= 5 && atof(userInput) >= 0)
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
/*	Checks that argument is integer and positive	*/
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
	printf("Press 0 to fill a struct to file, \
	1 read struct from file, \
	2 to print your struct, \
	3 to fill a struct and print it.:\n");
	
	char *input = readUserInput();
	int intInput = atoi(input);

	switch (intInput)
	{
		case 0:
		//fillStructFromFile(size, pointer);

//		fillStruct(size, pointer);
//		printStruct(size, pointer);
		//printStructFile(size, pointer);

		break;
		
		case 1:
//		fillStructFromFile(size, pointer);
		//printStructFile(size, pointer);
		break;

		case 2:
		printStruct(size, pointer);
		break;

		case 3:
		fillStruct(0, size, pointer);
		printStruct(size, pointer);
		break;		
		default:
		printf("Invalid input!\n");
	}
}

struct Student * askToAddStudents(int size, struct Student *pointer)
{
	printf("0 to add students, 1 to exit:\n");
	struct Student *addedStudents = NULL;																																																																																																																		
	int newSize = 0;
	char *input = readUserInput();
	int intInput = atoi(input);
	switch (intInput)
	{
		case 0:
		newSize = getNumOfStudents();
		addedStudents = addStudents(newSize, pointer);
		fillStruct(size, newSize+1, addedStudents);
		printStruct(size + newSize, addedStudents);
		countAverageGPA(size + newSize, addedStudents);
		break;

		case 1:
		break;

		default:
		break;
	}
	

	return addedStudents;
}

struct Student * addStudents(int newSize, struct Student *pointer)
{
	struct Student *newPointer = NULL;
	
	newPointer = realloc(pointer, newSize);

	if (newPointer == NULL)
	{
		printf("Memory reallocation failed!\n");
		newPointer = 0;
	}

	return newPointer;
}



void countAverageGPA(int size, struct Student *pointer)
{
	float sum = 0;
	float average = 0;
	for (int i = 0; i < size; i++)
	{
		sum += (pointer+i)->studentGPA;
	}
	average = sum / size;
	printf("This is the average of all GPA's: %.2f \n", average);
}







/*	FIle I/O	*/
/*
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
	
    	printf("Name: %s \t ID: %d \tGPA: %.2f\n", (read_struct + i)->studentName,
           (read_struct + i)->studentID, (read_struct + i)->studentGPA);	
		printf("Hello 376\n");

		printf("Hello 376\n");
		//printf("Name: ID: GPA: \n %s \n", readBuffer);

	
	fclose(filePointer);
}
*/