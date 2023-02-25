/*
File:			pointerDemo.c
Author:			Karri Korsu
Description:	pointer demo
*/

#include <stdio.h>

#define SIZE 3

void printArray(int *pointer, int size);

int main() 
{
    int demoArray[SIZE] = {2,4,6};
    int *pointer1 = &demoArray[0];

    printf("First value in array %d\n", *pointer1);

    //  Lets move the pointer to the next slot of the array
    pointer1++;

    
    printf("First value in array %d\n", *pointer1);

    printArray(pointer1, SIZE);

    return 0;
}

void printArray(int *pointer, int size)
{
    printf("First value in array %d\n", *pointer);

    //  Lets move the pointer to the next slot of the array
    pointer++;

    
    printf("First value in array %d\n", *pointer);
}