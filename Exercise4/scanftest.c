
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRLEN 100
void printArray(char* array);
void numOfNeg(int array[]);
int* createIntArray();


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



int main()
{
    


   
    return 0;
}




int checkUserInputBool(char* userInput)
{	//	if the first element is a dash or a number
	int flag = 2;
	if (userInput[0] == 45 || (userInput[0] >= 48 && userInput[0] <= 57))
	{	
		for (int i = 1; i < ARRLEN; i++)
		{
			if (userInput[i] >= 48 && userInput[i] <= 57)
			{	// if the element is a number: advance.
				flag = 1;
			}
			else 
			{	
				flag = 0;
				break;
				
				/*// if the element isnt a number 
				// for elements in userInput from i to end of array.
				if (userInput[i] == 0)
				{	// if the element is empty: advance.
					flag = 1;
				}
				else if (userInput[i] == 32)
				{	// if its something else than empty the input is invalid.
					flag = 0;
					break;
				}*/
			}
		}
	}
	else
	{
		flag = 0;
	}
	return flag;
}

void checkUserInput(char* userInput)
{

}

/*	5b Checks whether an input is a prime number or not.	*/
int primeNumCheck(char* userInput)
{
	
    // If the type checking function returns true
    int checkedInt = atoi(userInput);
    int possiblePrime = 1;
    if (checkedInt == 0)
    {
        printf("Your number is neither prime nor composite, it is %d\n", checkedInt);
        possiblePrime = 0;
    }
    else if (checkedInt == 1)
    {
        printf("Your number (%d) is prime\n", checkedInt);
        possiblePrime = 1;
    }
    else if (checkedInt < 0)
    {
        printf("Negative numbers can't be prime: %d\n", checkedInt);
        possiblePrime = 0;
    }
    else
    {
        for (int i = 2; i < checkedInt; i++)
        {	
            if (checkedInt % i == 0)
            {	//	if the integer an be divided by something
                //	other than itself or 1 its not prime.
                possiblePrime = 0;

                break;
            }
            else
            {
                possiblePrime = 1;
            }
        }
    }
    if (possiblePrime == 1)
    {
        printf("%d is a prime number", checkedInt);
    }
    else
    {
        printf("%d is not a prime number", checkedInt);
    } 

	return possiblePrime;
}





















