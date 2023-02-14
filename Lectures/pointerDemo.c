/*
File:			pointerDemo.c
Author:			Karri Korsu
Description:	pointer demo
*/

#include <stdio.h>

int main() 
{
    int number = 15;
    float pi = 3.14;
    int pointer = 0;

    //  Lets create two pointers
    int *pointer1 = NULL;
    float *pointer2 = NULL;

    //  Print variable values
    printf("Integer: %d \n", number);
    printf("Float: %.2f \n", pi);
    //print out pointer values
    printf("Pointer1: %p \n", pointer1);
    printf("Pointer2: %p\n", pointer2);
    
    //  lets make the pointers point to variables memory locations
    pointer1 = &number;
    pointer2 = &pi;
    pointer = &number;
    //printf("pointer: %d", pointer);

    printf("Memory locations:\n");
    printf("Pointer1: %p \n", pointer1);
    printf("Pointer2: %p\n", pointer2);
    printf("pointer: %p\n", pointer);     //dont do this


    //  Lets print out what is in the memory locations
    printf("memory addresses:\n");

    printf("In memory location %p there is value %d\n", pointer1, *pointer1);

    printf("In memory location %p there is value %f\n", pointer2, *pointer2);

    return 0;
}
