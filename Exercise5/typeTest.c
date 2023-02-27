#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void printArmstrong(char range[]);

int main() {

	char range[30] = "1000";
	printArmstrong(range);

    return 0;
}

void printArmstrong(char range[])
{
	int rangeInt = atoi(range);
	int cubedSum = 0;
	char nStr[30] = {'-'};
	
	for (int n = 0; n < rangeInt; n++)
	{
		sprintf(nStr, "%d", n);
		
		int nStrLen = strlen(nStr);
		cubedSum = 0;
		for (int i = 0; i < nStrLen; i++)
		{
			int nEleInt = nStr[i] - '0';
			cubedSum += pow(nEleInt,3);
			//printf("n:%d, cubed sum;%d, nStr;%c,nEleInt: %d\n",n, cubedSum, nStr[i], nEleInt);
		}
		if (n == cubedSum)
		{
			printf("%d is an armstrong number!\n", n);
		}
	}
}
