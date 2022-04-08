/*
 * Value.c
 *
 *  Created on: Jan 27, 2022
 *      Author: crua8
 */

#include <stdio.h>
#include <stdlib.h>
#include "Value.h"
#include "Cell.h"

int valueAtLocation(int* theBoard, int row, int col) {
	int* whichIsIt = theBoard + row*12 + col;
	int answer = *whichIsIt;

	return answer;
}

void swapValues(int* theBoard, Cell* cell) {

	Cell C1 = *cell;
	Cell C2;

	C2.row = cell -> row + 1;
	C2.col = cell -> col - 1;

	int* cell1Loc = (theBoard) + (C1.row * 12) + (C1.col);
	int* cell2Loc = (theBoard) + (C2.row * 12) + (C2.col);

	int dummy = *cell2Loc;

	*cell2Loc = *cell1Loc;
	*cell1Loc = dummy;
}
