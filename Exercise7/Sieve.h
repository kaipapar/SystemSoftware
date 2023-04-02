/* 
 * File:   		Sieve.h
 * Author: 		
 * Description: Header file for Sieve.c
 */

#ifndef SIEVE_H
#define SIEVE_H

#define ARRAYSIZE 20

void testSieve();
void sieveOfEra(char* userInput, int *arrayPointer); 
char* readUserInput();
int checkUserInput(char* userInput);

#endif 

