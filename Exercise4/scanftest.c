
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRLEN 100
void printArray(char* array);
void numOfNeg(int array[]);
int* createIntArray();

int main()
{
    //int *array = (int*)malloc(ARRLEN * sizeof(int));
    char *array = (char*) malloc(ARRLEN * sizeof(char*));
    printArray(array);
   
    return 0;
}

int* createIntArray()
{
    int *array = (int*)malloc(ARRLEN * sizeof(int));
    int i = 0;
    /*printf("enter a number:");
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
    printf("That is not a number!\n");*/
    printf("%s", array);

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
void printArray(char* array)
{
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
    }
}