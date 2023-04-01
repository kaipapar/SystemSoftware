/* 
 * File:   		Matrix.c
 * Author: 		
 * Description: 
 */

#include <stdio.h>
#include "Matrix.h"

#define SIZE 20 // size of matrix


void testMatrix() 
{

	printf("Hello from Matrix.\n");
	
	// get the maximum sum in all directions and compare them. The largest one is the biggest sum
	
	//

}

void getLargestSum()
{
	printf("26");
	
	const int twoDimensional[SIZE][SIZE] = {
	{ 8,  2, 22, 97, 38, 15, 00, 40, 00, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8},
	{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62, 00},
	{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
	{52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
	{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 18},
	{24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
	{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
	{67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94,  1},
	{24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
	{21, 36, 23,  9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95},
	{78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92},
	{16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57},
	{86, 56, 00, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
	{19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 04},
	{ 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
	{88, 36, 68, 87, 87, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53,  9},
	{ 4, 42, 16, 73, 38, 95, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36},
	{20, 69, 36, 41, 72, 30, 79, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16},
	{20, 73, 35, 29, 78, 31, 90, 81, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54},
	{ 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48}
	};
	
	int rowLargestSum = 0;
	int columnLargestSum = 0;
	int NWtoSELargestSum = 0;
	int SWtoNELargestSum = 0;
	int possibleSum = 0;
	printf("54");
	// get the largest sum in the rows
	for (int i = 0; i < (SIZE - 5); i + 5)
	{
		for (int j = 1; j < SIZE; j++)
		{
			possibleSum = twoDimensional[i][j] 
						+ twoDimensional[i+1][j] 
						+ twoDimensional[i+2][j] 
						+ twoDimensional[i+3][j] 
						+ twoDimensional[i+4][j];
						
			if (possibleSum > rowLargestSum)
			{
				rowLargestSum = possibleSum;
				printf("line64");
			}
		}
	}
	possibleSum = 0;
	printf("rowLargestSum: %d\n",rowLargestSum);
	
	// get the largest sum in the columns
	for (int k = 0; k<= (SIZE - 5); k + 5)
	{
		for (int i = 0; i < (SIZE - 5); i++)
		{
			possibleSum = twoDimensional[i][k] 
						+ twoDimensional[i][k+1] 
						+ twoDimensional[i][k+2] 
						+ twoDimensional[i][k+3] 
						+ twoDimensional[i][k+4];
						//+ twoDimensional[i][k+5];
			
			if (possibleSum > columnLargestSum)
			{
				columnLargestSum = possibleSum;
			}
		}
	}
	possibleSum = 0;
	printf("columnLargestSum: %d\n", columnLargestSum);
	
	// get the largest sum in NW to SE direction
	for (int k = 0; k <= (SIZE - 5); k + 5) // moves the sum in vertical direction, 5 steps at a time
	{
		for (int j = 0; j<= (SIZE - 5); j++) // moves the sum in horizontal direction from left to right
		{
			possibleSum = twoDimensional[j][k] 		// [0][0]	[1][0]
						+ twoDimensional[j+1][k+1] 	// [1][1]	[2][1]
						+ twoDimensional[j+2][k+2] 	// [2][2]	[3][2]
						+ twoDimensional[j+3][k+3] 	// [3][3]	[4][3]
						+ twoDimensional[j+4][k+4]; 	// [4][4]	[5][4]
						//+ twoDimensional[j+5][k+5];	// [5][5]	[6][5]
						
			if (possibleSum > NWtoSELargestSum)
			{
				NWtoSELargestSum = possibleSum;
			}
		}
		possibleSum = 0;	
	}
	printf("NWtoSELargestSum: %d \n", NWtoSELargestSum);
	
	// get the largest sum in SW to NE direction
	for (int k = 0; k <= (SIZE - 5); k + 5)) // moves the sum in vertical direction 5 steps at a time
	{
		for (int j = 4; j >= SIZE; j++) // moves the sum in horizontal direction from left to right
		{
			possibleSum = twoDimensional[j][k] 		// [5][0]	[6][0]
						+ twoDimensional[j-1][k+1]	// [4][1]	[5][1]
						+ twoDimensional[j-2][k+2] 	// [3][2]
						+ twoDimensional[j-3][k+3] 	// [2][3]
						+ twoDimensional[j-4][k+4]; 	// [1][4]
						//+ twoDimensional[j-5][k+5];	// [0][5]	[1][5]
			 
			if (possibleSum > SWtoNELargestSum)
			{
				SWtoNELargestSum = possibleSum;
			}
		}
	}
	

	
	
	printf("SWtoNELargestSum: %d \n", SWtoNELargestSum);
	// compare the sums
	
	int leftMax = max(rowLargestSum, columnLargestSum);
	int rightMax = max(NWtoSELargestSum, SWtoNELargestSum);
	printf("leftmax : %d, rightmax : %d\n", leftMax, rightMax);
	int maxSum = max(leftMax, rightMax);	
	printf("The maximum sum of five adjacent elements: %d", maxSum);

}

int max(int integer1, int integer2)
{
	if (integer1 > integer2)
	{
		return integer1;
	}
	else
	{
		return integer2;
	}
}

