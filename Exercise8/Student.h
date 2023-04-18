/*
File:			Student.h
Author:			Karri Korsu
Description:	Header file for Student.c
*/

#ifndef STUDENT_H
#define STUDENT_H

#define ARRAYSIZE 20


void testStudent();



struct Student * createStructArray(int size);

void printStruct(int size, struct Student *pointer);
void fillStruct(int oldSize, int newSize, struct Student *pointer);
char* readUserInput();

int checkUserInputID(char* userInput);

int checkUserInputName(char* userInput);
int checkUserInputGPA(char* userInput);
int checkUserInputSize(char* userInput);

int getNumOfStudents();

struct Student * askToAddStudents();
struct Student * addStudents(int newSize, struct Student *pointer);
void countAverageGPA(int size, struct Student *pointer);

/*
void askToFillStruct(int size, struct Student *pointer);
void fillStructFromFile(int size, struct Student *pointer);
void printStructFile(int size, struct Student *pointer);
*/
#endif

