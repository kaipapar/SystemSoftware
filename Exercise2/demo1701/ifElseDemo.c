//File:			ifElseDemo.c
//Author:		Karri Korsu
//Description:	If else demo + for loops

#include <stdio.h>

int main() {

	char letter = 'i';			//char variable contains just one character, it can be symbols, numbers, letters
	
	if (letter == 'Y') {		//if ( arguments ) { loop contents }
	
		printf("You answered yes.\n");
		
	} else if (letter == 'N') {		// } else if () { structure is to be used, or
	
		printf("You answered no.\n");
	
	} else {
	
		printf("Please type yes or no.\n");
	}
	
	int number = 15;
	//int iterator = 0; can be defined here also.
	for (int i = 0; i < number; i++) { //i is better to define here
	//loops while i is less than number and adds 1 to i at the end of every cycle
	
	// number -= 2; works
	// number--; works
	
		printf("%d ", i);
	
	
	}
	

	return 0;
}
