/*
File:			pointerDemo.c
Author:			Karri Korsu
Description:	pointer demo
*/

#include <stdio.h>

#define SIZE 3

int main() 
{
    int demoArray[SIZE] = {2,4,6};
    int *pointer1 = &demoArray[0];

    printf("First value in array %d\n", *pointer1);

    return 0;
}
