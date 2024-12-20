/*
File:			Exercise4.c	
Author:			Karri Korsu
Description:	Answers to Tasks 3 - 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRLEN 100


int* createIntArray();
int numOfNeg(int* array);
int sumOfInt(int* array);
int sumOfPosDivThree(int* array);


int randNumGen(int num1, int num2);
void gradeCheck(int exPoints);


char* readUserInput();
int checkUserInput(char* userInput);
int primeNumCheck(char* userInput);





int main()
{
    // Task 3
	int *intArray = createIntArray();

	printf("Number of negative numbers in the array: %d\n", numOfNeg(intArray));

	printf("The sum of integers in the array: %d\n", sumOfInt(intArray));
	
	printf("Sum of positive integers which can be divided by three: %d\n", sumOfPosDivThree(intArray));

	// Task 4
	int randNum = randNumGen(-15, -7);

	printf("This is a random number: %d\n", randNum);

    gradeCheck(randNum);
	

	// Task 5
	char *userInput = readUserInput();
	

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
int numOfNeg(int array[])
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
	return numberOfNegs;
    
}


/*	3b Returns the sum of all integers in an array	*/
int sumOfInt(int array[])
{
	int sumOfIntegers = 0;
	int i = 0;
	while (array[i] != 0)
	{
		sumOfIntegers += array[i];
		i++;
	}
	return sumOfIntegers;
}


/*	3c Returns the sum of positive integers in an array 
	which can be divided by three	*/
int sumOfPosDivThree(int array[])
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
	return sumOfPositives;
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



/*	5b Asks for user input and returns that input as char array	*/
char* readUserInput()
{
	char *array = (char*) malloc(ARRLEN * sizeof(char*));
	printf("Enter an integer: \n");
	scanf(" %s", array);

	return array;
}


/*	5b Checks whether userInput char array can be interpreted as integer
	returns 0 == False, 1 == True	*/
int checkUserInput(char* userInput)
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
				// if the element isnt a number 
				// for elements in userInput from i to end of array.
				if (userInput[i] == 0)
				{	// if the element is empty: advance.
					flag = 1;
				}
				else if (userInput[i] == 32)
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


/*	5b Checks whether an input is a prime number or not.	*/
int primeNumCheck(char* userInput)
{
	int possiblePrime = 0;
	if (checkUserInput(userInput) == 1)
	{	// If the type checking function returns true
		int checkedInt = atoi(userInput);
		if (checkedInt == 0)
		{
			printf("Your number is neither prime nor composite, it is %d\n", checkedInt);
		}
		else if (checkedInt == 1)
		{
			printf("Your number (%d) is prime\n", checkedInt);
			possiblePrime = 1;
		}
		else if (checkedInt < 0)
		{
			printf("Negative numbers can't be prime: %d\n", checkedInt);
		}
		else
		{
			for (int i = 1; i < checkedInt; i++)
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
			if (possiblePrime == 1)
			{
				printf("%d is a prime number.\n", checkedInt);
			}
			else
			{
				printf("%d is not a prime number.\n", checkedInt);
			}

		}
	}
	else if (checkUserInput(userInput) == 0)
	{
		printf("Invalid input!\n");


	}
	else
	{
		printf("Hmm, something went wrong. Flag : %d", checkUserInput(userInput));

	}
	//	Returns 0 for non prime numbers, 
	return possiblePrime;
}




