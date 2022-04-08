/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "Cell.h"

bool tests()
{
	bool allOK = true; //so far, so good

	//test the functions that get used
	//order the tests from simplest first -- this produces building blocks for use in more complex tests
	//check how functions are used in production code, this gives clues about how to provide the arguments for the invocation
	bool ok0 = testLoad();
//	bool ok1 = testIsValid();
//	bool ok2 = testIsEligible();
//	bool ok3 = testSettle();
	bool ok4 = testValue();
	bool ok5 = testSwap();
	bool ok6 = testReturn();
	allOK = ok0 && /* ok1 && ok2 && ok3 && */ ok4 && ok5 && ok6;
	return allOK;
}

bool testLoad()
{
	bool ok = true; //so far
	puts("Starting test load");
	fflush(stdout);
	//setup
	int* board = (int*) malloc (11*12*sizeof(int));
	int testRow = 6;
	int testCol = 4;

	//trial
	load(board, 11,12);
	int* whichIsIt = board+ testRow*12 + testCol;
	int answer = *whichIsIt;
	int rightAnswer = 3*testRow + 5*testCol;
	ok = (answer == rightAnswer);


	//judgment
	if(ok)
	{
		puts("load passed its test");

	} else{
		puts("load did not pass its test");
	}

	return ok;;
}

bool testIsValid()
{
	bool ok = true; //so far

	//set up
	Location** board = (Location**) malloc (11*12*sizeof(Location*));
	//init(board, 11,12);
	int testRow = 6;
	int testCol =4;

	//trial
	bool answer = isValid(board, testRow, testCol);
	bool rightAnswer = true;
	bool ok1 = answer == rightAnswer;
	testCol  = 23;
	answer = isValid(board, testRow, testCol);
	rightAnswer = false;
	bool ok2 = answer == rightAnswer;
	ok = ok1 && ok2;

	//render judgment
	if(ok)
	{
		puts("isValid passed its test");

	} else{
		puts("isValid did not pass its test");
	}



	return ok;
}
bool testIsEligible()
{
	bool ok = true; //so far
	//what does it take to test isEligible?


	//setup
	Location** board = (Location**) malloc (11*12*sizeof(Location*));
	//init(board, 11,12);
	int testrow =3;
	int testcol =7;

	//trial
	bool answer = isEligible(board, testrow, testcol);
	bool rightAnswer = true;
	bool ok1 = (answer ==rightAnswer);
	testcol =-5;
	rightAnswer = false;
	bool ok2= (answer ==rightAnswer);
	ok = ok1 && ok2;

	//judgment
	if(ok)
	{
		puts("isEligible passed its test");

	} else{
		puts("isEligible did not pass its test");
	}
	return ok;
}
bool testSettle()
{
	bool answer = true; //so far

	return answer;
}
bool testSavePayload()
{
	bool answer = true; //so far

	return answer;
}
bool testPrintList()
{
	bool answer = true; //so far

	return answer;
}

bool testValue() {
	bool ok = true; //so far

	int testRow = 5;
	int testCol = 4;

	//set up
	int* aBoard = (int*) malloc (11*12*sizeof(int));
	load(aBoard, 11,12);

	int val = valueAtLocation(aBoard, testRow, testCol);

	int rightAnswer = 3*testRow + 5*testCol;

	if (val != rightAnswer) ok = false;

	//judgment
	if(ok)
	{
		puts("valueAt passed its test");
		// puts("value: " + val);

	} else{
		puts("valueAt did not pass its test");
		// puts("value: " + val);
	}
	return ok;
}

Cell* choose(int nrows, int ncols) {
	Cell* rP = (Cell*) malloc (sizeof(Cell));
	rP -> row = rand()%nrows;
	rP -> col = rand()%ncols;

	return rP;
}

Cell* getRandCell(int* theBoard, int nrows, int ncols) {
	Cell* cell = choose(nrows, ncols);
	return cell;
}

bool testSwap() {
	bool ok = true; //so far

	int nrows = 11;
	int ncols = 12;

	//set up
	int* bBoard = (int*) malloc (11*12*sizeof(int));
	load(bBoard, nrows, ncols);

	Cell* cell = getRandCell(bBoard, nrows, ncols);

	Cell c1 = *cell;
	Cell c2;

	c2.row = cell -> row + 1;
	c2.col = cell -> col - 1;

	int val1 = valueAtLocation(bBoard, c1.row, c1.col);
	int val2 = valueAtLocation(bBoard, c2.row, c2.col);

	swapValues(bBoard, cell);

	int val3 = valueAtLocation(bBoard, c1.row, c1.col);
	int val4 = valueAtLocation(bBoard, c2.row, c2.col);

	if ((val1 != val4) && (val2 != val3)) ok = false;

	//judgment
	if(ok)
	{
		puts("swapValue passed its test");
	} else{
		puts("swapValue did not pass its test");
	}
	return ok;
}

bool testReturn() {
	bool ok = true; //so far

	int nrows = 11;
	int ncols = 12;

	//set up
	int* cBoard = (int*) malloc (nrows*ncols*sizeof(int));
	load(cBoard, 11,12);

	Cell* cell1 = getRandCell(cBoard, nrows, ncols);

	Cell* cell2 = getRandCell(cBoard, nrows, ncols);

	swapValues(cBoard, cell1);

	Cell c2 = *cell2;

	int val = valueAtLocation(cBoard, c2.row, c2.col);

	printf("\nreturnTest:");
	printf("\nLocation: (%d, %d)", c2.row, c2.col);
	printf("\nValue: %d", val);
	printf("\n\n");

	//judgment
	if(ok)
	{
		puts("returnTest passed its test");
	} else{
		puts("returnTest did not pass its test");
	}
	return ok;
}
