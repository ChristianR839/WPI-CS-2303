/*
 * Board.h
 *
 *  Created on: Mar 2, 2022
 *      Author: crua8
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdlib>

class Board {

private:
	char* data;
	int sideLength;
	int numShips;

public:
	Board(int sideLength);
	virtual ~Board();

	void processGuess(int x, int y);
	bool placeShip(int x, int y, int direction, int length, char type);
	bool checkInput(std::string x);
	void setupShip(Board theboard, int length, char type);
	void setupOppShip(int length, char type);

	void printBoard(char* b);
	void printBoard2();
	char getSpaceVal(char* b, int x, int y);
	void setSpaceVal(char* b, int x, int y, char type);
	bool getHasShip(char* b, int x, int y);
	bool checkAllType(char* b, char type);
	bool allSunk(char* b);
	bool sameShot(char* b, int x, int y);
	bool hitOrMiss(char* b, int x, int y);
	void updateOppVis(char* bOpp, char* bOppVis, Board* opp, Board* oppVis);
	void guessLoop(Board* you, Board* opp, Board* oppVis);
};

#endif /* BOARD_H_ */
