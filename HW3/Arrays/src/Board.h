/*
 * Board.h
 *
 *  Created on: Nov 9, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdbool.h>
#include <stdlib.h>
#include "Location.h"

void load(int* theBoard, int nrows, int ncols);
bool isValid(Location** theBoard, int row, int col);
bool isEligible(Location** theBoard, int row, int col);
void settle(Location** theBoard, int row, int col);
void adjustNeighbors(Location** theBoard, int row, int col);

#endif /* BOARD_H_ */
