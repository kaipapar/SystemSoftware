/*
File:			Exercise4.c	
Author:			Karri Korsu
Description:	Answers to Tasks 3 - 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRLEN 100

/*	Task 3	*/
int* createIntArray();
void numOfNeg(int array[]);
void sumOfInt(int array[]);
void sumOfPosDivThree(int array[]);

/*	Task 4	*/
int randNumGen(int num1, int num2);
void gradeCheck(int exPoints);

/*	Task 5	*/
char* readUserInput();
int checkUserInput(char* userInput);
void primeNumCheck(char* userInput);

/*	Misc	*/
void printArray(int array[]);
void printArrayTilZero(int array[]);



int main()
{
    //int *intArray = createIntArray();
	

    /*numOfNeg(intArray);
	sumOfInt(intArray);
	sumOfPosDivThree(intArray);
	*/
    //printArray(intArray);
	randNumGen(0,120);
    gradeCheck(randNumGen(0, 120));
	
	char *userInput = readUserInput();
	printf("%s", userInput);
	primeNumCheck(userInput);


    return 0;
}


/*	3 Creates an array consisting of integers which the user inputs	*/
int* createIntArray()
{
    int *array = (int*)malloc(ARRLEN * sizeof(int));
    int i = 0;
    printf("Enter an integer:");

    while (scanf("%d", &array[i]) == 1)
    {
        printf("You entered integer: %d \n", array[i]);
        if (array[i] == 0)
        {
            break;
        }
        else 
        {
            i++;
        }
    }
    printf("You entered 0 or something that isn't an integer!\n");

    return array;
}


/*	3a Returns the amount of negative numbers in an array	*/
void numOfNeg(int array[])
{
    int numberOfNegs = 0;
	int i = 0;

	while (array[i] != 0)
	{
		if (array[i] < 0)
		{
			numberOfNegs++;
		}
		i++;
	}
    printf("number of negs: %d\n", numberOfNegs);
}


/*	3b Returns the sum of all integers in an array	*/
void sumOfInt(int array[])
{
	int sumOfIntegers = 0;
	int i = 0;
	while (array[i] != 0)
	{
		sumOfIntegers += array[i];
		i++;
	}
	printf("The sum of integers in the array: %d\n", sumOfIntegers);
}


/*	3c Returns the sum of positive integers in an array 
	which can be divided by three	*/
void sumOfPosDivThree(int array[])
{
	int sumOfPositives = 0;
	int i = 0;
	while (array[i] != 0)
	{
		if (array[i] > 0 && (array[i] % 3) == 0)
		{
		sumOfPositives += array[i];
		}
		i++;
	}
	printf("Sum of positive integers which can be divided by three: %d",
	 sumOfPositives);
}

/*	4a Returns a random integer in range which is taken as an argument*/
/*	Random number generator		*/
int randNumGen(int num1, int num2)
{
	time_t t = 0;
	srand((unsigned) time(&t));

	int range = 0;
	int rangeShift = 0;
	
	if (num1 > num2)
	{	//if the first number is bigger
		range = (num1 - num2 + 1);
		rangeShift = num2;
	}
	else if (num2 > num1)
	{	//if the second number is bigger
		range = (num2 - num1 + 1);
		rangeShift = num1;
	}
	else
	{	//if the two numbers are the same.
		range = 1;
		rangeShift = num1; 
	}
	
	int randNum = rand() % range + rangeShift;
	
	return randNum;
}


/*	4b returns a grade corresponding to requirements	*/
void gradeCheck(int exPoints)
{
	int grade = 0;
	if (exPoints >= 0 && exPoints <= 120)
	{
		if (exPoints < 60)
		{
			grade = 0;
		}
		else if (exPoints < 72)
		{
			grade = 1;
		}
		else if (exPoints < 84)
		{
			grade = 2;
		}
		else if (exPoints < 96)
		{
			grade = 3;
		}
		else if (exPoints < 108)
		{
			grade = 4;
		}
		else 
		{
			grade = 5;
		}
		printf("This is the grade for %d points: %d\n", exPoints, grade);
	}
	else if (exPoints < 0)
	{
		printf("You have negative points, sorry.\n");
	}
	else
	{
		printf("Wow! You have more points than what is possible.\n");
	}
}

/*	5b	*/

/*	Asks for user input and returns that input as char array	*/
char* readUserInput()
{

	char *array = (char*) malloc(ARRLEN * sizeof(char*));
	scanf("%s", array);

	return array;
}

/*	Checks whether userInput char array can be interpreted as integer
	returns 0 == False, 1 == True	*/
int checkUserInput(char* userInput)
{	//	if the first element is a dash or a number
	if (userInput[0] == 45 || (userInput[0] > 48 && userInput[0] < 57))
	{	
		for (int i = 1; i < ARRLEN; i++)
		{
			if (userInput[i] > 48 && userInput[i] < 57)
			{	// if the element is a number advance.
				continue;
			}
			else 
			{	// if the element isnt a number 
				for (i = i - 1; i < ARRLEN; i++)
				{	// for elements in userInput from i to end of array.
					if (userInput[i] == 0)
					{	// if the element is <space> == 0 advance.
						continue;
					}
					else
					{	// if its something else than space the input is invalid.
						break;
						return 0;
					}
				}
			}
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

void primeNumCheck(char* userInput)
{
	if (checkUserInput(userInput) == 1)
	{
		int checkedInt = atoi(userInput);
		int possiblePrime = 0;
		if (checkedInt == 0)
		{
			printf("Your number is neither prime nor composite, it is %d\n", checkedInt);
		}
		else if (checkedInt == 1)
		{
			printf("Your number (%d) is prime\n", checkedInt);
		}
		else if (checkedInt < 0)
		{
			printf("Negative numbers can't be prime: %d\n", checkedInt);
		}
		else
		{
			for (int i = 2; i < checkedInt; i++)
			{
				if (checkedInt % i == 0)
				{
					possiblePrime = 1;
					break;
				}
			}
			if (possiblePrime == 0)
			{
				printf("%d is a prime number.\n", checkedInt);
			}
			else
			{
				printf("%d is not a prime number.\n", checkedInt);
			}
		}
	}
	else
	{
		printf("Invalid input!\n");
	}
}

/*	Prints all elements of an integer array	*/
void printArray(int array[])
{
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
    }
}


/*	Prints all elements of an integer array until the next element is 0*/
void printArrayTilZero(int array[])
{
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("array element %d: %d\n", i, array[i]);
		if (array[i] == 0)
		{
			break;
		}
    }
}
