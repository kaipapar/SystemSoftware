/*
File:			Student.h
Author:			Karri Korsu
Description:	Header file for Student.c
*/

#ifndef STUDENT_H
#define STUDENT_H

#define ARRAYSIZE 20


void testStudent();
struct Student * createStructArray();
void printStruct(int size, struct Student *pointer);
void fillStruct(int size, struct Student *pointer);
char* readUserInput();
int checkUserInput(char* userInput);



#endif

