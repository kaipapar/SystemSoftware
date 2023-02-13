#define ARRLEN 100

void printArray(int array[]);
void printArrayTilZero(int array[]);

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