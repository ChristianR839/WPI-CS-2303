/*
 * Board.c
 *
 *  Created on: Nov 9, 2021
 *      Author: theresesmith
 */

#include "Board.h"

void load(int* theBoard, int nrows, int ncols)
{

	for(int row = 0; row<nrows; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			int* whereOnBoard = theBoard + row*ncols + col;
			*whereOnBoard = 3*row+5*col;

			// Also works, but is hard to read:
			// *(theBoard + row*ncols + col) = 3*row + 5*col;
		}
	}

}

bool isValid(Location** theBoard, int row, int col)
{
	bool eligible = true;


	return eligible;
}
bool isEligible(Location** theBoard, int row, int col)
{
	bool eligible = true;


	return eligible;
}
void settle(Location** theBoard, int row, int col)
{




}
void adjustNeighbors(Location** theBoard, int row, int col)
{




}
