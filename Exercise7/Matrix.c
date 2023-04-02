/* 
 * File:   			Matrix.c
 * Author: 			Karri Korsu
 * Description: 	Find the greatest sum of 5 adjacent elements in matrix
 */

#include <stdio.h>
#include "Matrix.h"

void testMatrix() 
{
	printf("Hello from Matrix.\n");
}

void getLargestSum()
{

	/*
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
	};*/
	const int twoDimensional[SIZE][SIZE] = {
	{ 3,  2, 21, 29, 43, 15, 00, 40, 00, 18,  4,  5,  9, 93, 51, 22, 50, 98, 82,  3},
	{46, 46, 88, 40, 29, 32,  1, 59, 50, 39, 28, 40, 83, 74, 58, 43,  4, 55, 52, 00},
	{32, 36, 31, 83, 55, 88, 14, 29, 94, 91, 30, 59, 54, 33, 30,  4, 39, 23, 13, 55},
	{51, 90, 18, 14,  4, 50, 11, 41, 59, 13, 62, 55,  2, 32, 55, 92, 32,  1, 14, 81},
	{12, 32, 25, 82, 52, 58, 54, 38, 32, 82, 14, 54, 11, 40, 40,  1, 55, 74, 14, 30},
	{14, 48, 41, 50, 88,  4, 14,  1, 74, 18, 74, 54, 93, 14, 34, 10, 14, 19, 11, 50},
	{41, 93, 31,  1, 54, 14, 59, 10, 25, 43, 40, 59, 59, 54, 90, 55,  1, 43, 54, 88},
	{59, 25, 20, 61,  1, 52, 22, 20, 18, 54, 94, 42, 54,  3, 40, 92, 55, 49, 94, 22},
	{24, 55, 62,  5, 55, 94, 99, 25, 99, 29, 93, 93, 18, 34, 14, 33, 74, 89, 54, 91},
	{11, 14, 14,  9, 18, 00, 18, 74, 10, 14, 14, 14, 00, 52, 74, 99, 94, 42, 74, 18},
	{93, 29, 54,  1, 22, 18, 42, 59, 25, 93,  3, 30,  3, 52, 25, 93,  9, 53, 55, 92},
	{25, 42,  5, 42, 18, 14, 42, 49, 55, 62, 33, 24, 00, 29, 53, 24, 13, 29, 35, 59},
	{35, 55, 00, 43, 14, 92, 39,  9,  5, 73, 73, 39, 74, 50, 22, 62, 52, 54, 29, 62},
	{29, 30, 32, 62,  5, 94, 46, 59,  1, 93, 92, 23, 35, 52, 29, 99,  3, 39, 55, 30},
	{ 4, 52,  3, 34, 99, 14, 99, 25,  9, 99, 59, 42, 25, 25, 25, 99, 74, 29, 93, 55},
	{33, 14, 62, 39, 59, 52, 20, 92,  3, 13, 73, 59, 13, 55, 22, 32, 54, 94, 54, 59},
	{ 4, 42, 25, 94, 43, 25, 46, 22, 24, 94, 92,  1,  3, 14, 29, 42, 40, 52, 18, 13},
	{20, 58, 14, 42, 82, 40, 24, 33, 73, 52, 99, 59, 32, 58, 58, 35, 93,  4, 14, 25},
	{20, 94, 14, 29, 93, 42, 90,  2, 84, 42, 46, 82, 43, 35, 32, 25, 24, 58,  5, 54},
	{ 2, 80, 54, 82, 34, 52, 54, 59, 25, 92, 74, 43, 52, 74, 52,  2, 39, 29, 59, 43}
	};
	int rowLargestSum = 0;
	int columnLargestSum = 0;
	int NWtoSELargestSum = 0;
	int SWtoNELargestSum = 0;
	int possibleSum = 0;

	// get the largest sum in the rows
	for (int y = 0; y < SIZE; y++) // moves the sum in horizontal direction from left to right
	{
		for (int x = 0; x <= (SIZE - 5); x++) // moves the sum in vertical direction from up to down
		{
			possibleSum = twoDimensional[y][x] 
						+ twoDimensional[y][x+1] 
						+ twoDimensional[y][x+2] 
						+ twoDimensional[y][x+3] 
						+ twoDimensional[y][x+4];
						
			if (possibleSum > rowLargestSum)
			{
				rowLargestSum = possibleSum;
			}
		}
	}
	possibleSum = 0;
	printf("rowLargestSum: %d\n",rowLargestSum);
	
	// get the largest sum in the columns
	for (int x = 0; x < SIZE; x++) // moves the sum in horizontal direction from left to right
	{
		for (int y = 0; y <= (SIZE - 5); y++) // moves the sum in vertical direction from up to down
		{
			possibleSum = twoDimensional[y][x] 
						+ twoDimensional[y+1][x] 
						+ twoDimensional[y+2][x] 
						+ twoDimensional[y+3][x] 
						+ twoDimensional[y+4][x];
						
			if (possibleSum > columnLargestSum)
			{
				columnLargestSum = possibleSum;
			}
		}
	}
	possibleSum = 0;
	printf("columnLargestSum: %d\n", columnLargestSum);
	
	// get the largest sum in NW to SE direction
	for (int x = 0; x <= (SIZE - 5); x++) // moves the sum in horizontal direction from left to right
	{
		for (int y = 0; y<= (SIZE - 5); y++) // moves the sum in vertical direction from up to down
		{
			possibleSum = twoDimensional[y][x] 		// [0][0]	[1][0]
						+ twoDimensional[y+1][x+1] 	// [1][1]	[2][1]
						+ twoDimensional[y+2][x+2] 	// [2][2]	[3][2]
						+ twoDimensional[y+3][x+3] 	// [3][3]	[4][3]
						+ twoDimensional[y+4][x+4]; 	// [4][4]	[5][4]
						
			if (possibleSum > NWtoSELargestSum)
			{
				NWtoSELargestSum = possibleSum;
			}
		}
		possibleSum = 0;	
	}
	printf("NWtoSELargestSum: %d \n", NWtoSELargestSum);
	
	// get the largest sum in SW to NE direction
	for (int x = 0; x <= (SIZE - 5); x++) // moves the sum in horizontal direction from left to right
	{
		for (int y = 4; y < SIZE; y++) // moves the sum in vertical direction from up to down
		
		{
			possibleSum = twoDimensional[y][x] 		// [5][0]	[6][0]
						+ twoDimensional[y-1][x+1]	// [4][1]	[5][1]
						+ twoDimensional[y-2][x+2] 	// [3][2]
						+ twoDimensional[y-3][x+3] 	// [2][3]
						+ twoDimensional[y-4][x+4]; 	// [1][4]
			
			if (possibleSum > SWtoNELargestSum)
			{
				SWtoNELargestSum = possibleSum;	
			}
		}
	}
	printf("SWtoNELargestSum: %d \n", SWtoNELargestSum);
	
	// compare the sums
	int horiVert = max(rowLargestSum, columnLargestSum);
	int diagonal = max(NWtoSELargestSum, SWtoNELargestSum);
	printf("horizontal, vertical max : %d, diagonal max : %d\n", horiVert, diagonal);
	int maxSum = max(horiVert, diagonal);	
	printf("The maximum sum of five adjacent elements: %d\n", maxSum);

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

