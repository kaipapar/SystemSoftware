
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRLEN 100
void printArray(int array[]);
void numOfNeg(int array[]);
int* createIntArray();

int main()
{
    char inte[ARRLEN] = {0};
    if (scanf("%s", &inte) == 1)
    {
        
           printf("Line 16 %s", inte);
           

    }
    
   
    return 0;
}

int* createIntArray()
{
    int *array = (int*)malloc(ARRLEN * sizeof(int));
    int i = 0;
    printf("enter a number:");
    while (scanf("%d", &array[i]) == 1)
    {
        printf("Your number is: %d \n", array[i]);
        if (array[i] == 0)
        {
            break;
        }
        else 
        {
            
            i++;
        }
    }
    printf("That is not a number!\n");

    return array;
}

void numOfNeg(int array[])
{
    int numberOfNegs = 0;
    for (int i = 0; i < ARRLEN; i++)
    {
        if (array[i] < 0)
        {
            numberOfNegs++;
        }
        else if (array[i] == 0)
        {
            break;
        }
    }
    printf("number of negs: %d\n", numberOfNegs);
}

// function to print array contents
void printArray(int array[])
{
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
    }
}