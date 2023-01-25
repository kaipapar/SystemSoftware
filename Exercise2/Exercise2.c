/*
File:			scanf_ex	
Author:			Karri Korsu
Description:	read 2 int from user one by one.
*/

#include <stdio.h>

int main() {
	char num1;
	char num2;
	//char input;
	printf("Input an integer: ");
	scanf("%c", &num1);
	printf("===\nInput another integer: ");
	scanf(" %c", &num2);
	printf("%d",num1);
	
	int num3 = num1 - '0';
	
	printf("\n%d",num3);
	return 0;
}

//use an if 
