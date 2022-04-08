//============================================================================
// Name        : Battleship.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Board.h"

using namespace std;

int main() {
	// cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "BATTLESHIP" << endl << endl;

	Board* board = new Board(10);
	//where to place ships
	// make carrier
	cout << "Place Carrier" << endl;
	board->setupShip(*board, 5, 'c');

	board -> printBoard2();

	cout << "Place Battleship" << endl;
	board->setupShip(*board, 4, 'b');

	board -> printBoard2();

	cout << "Place Cruiser" << endl;
	board->setupShip(*board, 3, 'r');

	board -> printBoard2();

	cout << "Place Submarine" << endl;
	board->setupShip(*board, 3, 's');

	board -> printBoard2();

	cout << "Place Destroyer" << endl;
	board->setupShip(*board, 2, 'd');


	// cout << "Your Board:" << endl;
	// board -> printBoard();

	Board* oppVis = new Board(10);
	oppVis->setupOppShip(5, '~');
	oppVis->setupOppShip(4, '~');
	oppVis->setupOppShip(3, '~');
	oppVis->setupOppShip(3, '~');
	oppVis->setupOppShip(2, '~');

	Board* opp = new Board(10);
	opp->setupOppShip(5, 'c');
	opp->setupOppShip(4, 'b');
	opp->setupOppShip(3, 'r');
	opp->setupOppShip(3, 's');
	opp->setupOppShip(2, 'd');

//	cout << endl << "Enemy Board (nonvis):" << endl;
//	opp->printBoard();
//	cout << endl << "Enemy Board (vis):" << endl;
//	oppVis->printBoard();

	opp->guessLoop(board, opp, oppVis);
}

