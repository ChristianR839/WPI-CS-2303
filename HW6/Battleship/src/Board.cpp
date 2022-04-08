/*
 * Board.cpp
 *
 *  Created on: Mar 2, 2022
 *      Author: crua8
 */

#include "Board.h"

#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

Board::Board(int sideLength) {
	this->sideLength = sideLength;
	this->data = (char*) malloc(sideLength * sideLength * sizeof(char));

	for (int y = 0; y < sideLength; y += 1) {
		for (int x = 0; x < sideLength; x += 1) {
			char* space = data + (sideLength * y) + x;
			*space = '~';
		}
	}
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

bool Board::checkInput(string x) {
	string zero = "0";
	string one = "1";
	string two = "2";
	string three = "3";
	string four = "4";
	string five = "5";
	string six = "6";
	string seven = "7";
	string eight = "8";
	string nine = "9";
	if (x == zero || x == one || x == two || x == three || x == four
			|| x == five || x == six || x == seven || x == eight || x == nine) {
		return true;
	} else {
		return false;
	}
}

bool Board::placeShip(int x, int y, int direction, int length, char type) {
	if (numShips == 5) {
		return false;
	}
	// 1) We can put ship here
	// a) check if x, y is in bounds
	if (!(x >= 0 && x < sideLength && y >= 0 && y < sideLength)) {
		return false;
	}
	// b) check if other end is in bounds
	int otherX = x;
	int otherY = y;

	if (direction == 0) {
		otherY -= (length - 1);
	} else if (direction == 1) {
		otherX += (length - 1);
	} else if (direction == 2) {
		otherY += (length - 1);
	} else if (direction == 3) {
		otherX -= (length - 1);
	}

	if (!(otherX >= 0 && otherX < sideLength && otherY >= 0
			&& otherY < sideLength)) {
		return false;
	}
	// 2) If we can put the ship on the board

	for (int i = 0; i < length; i += 1) {

		int checkX;
		int checkY;

		if (i == 0) {
			checkX = x;
			checkY = y;
		}

		if (getHasShip(data, checkX, checkY)) {
			return false;
		}

		if (direction == 0) {
			checkY -= 1;
		} else if (direction == 1) {
			checkX += 1;
		} else if (direction == 2) {
			checkY += 1;
		} else if (direction == 3) {
			checkX -= 1;
		}
	}
	//3) if we can put the ship on the board
	// newShip->placeShip(x, y, direction);

	for (int i = 0; i < length; i += 1) {

		int theX;
		int theY;

		if (i == 0) {
			theX = x;
			theY = y;
		}

		if (i != 0) {
			if (direction == 0) {
				theY -= 1;
			} else if (direction == 1) {
				theX += 1;
			} else if (direction == 2) {
				theY += 1;
			} else if (direction == 3) {
				theX -= 1;
			}
		}

		setSpaceVal(data, theX, theY, type);
	}

	numShips += 1;
	return true;
}

void Board::setupShip(Board theBoard, int length, char type) {
	string a;
	string b;
	string c;
	bool runCarr = true;
	bool runCleanCarr = true;
	while (runCarr) {
		while (runCleanCarr) {
			bool agood = false;
			bool bgood = false;
			bool cgood = false;
			cout << "Please input x and y coordinates (0 to 9 inclusive):"
					<< endl;
			cin >> a;
			if (theBoard.checkInput(a)) {
				agood = true;
			}
			cin >> b;
			if (theBoard.checkInput(b)) {
				bgood = true;
			}
			cout << "Please input direction of ship (0-3 inclusive):" << endl;
			cin >> c;
			if (theBoard.checkInput(c)) {
				cgood = true;
			}

			// cout << "a: " << theBoard.checkInput(a) << endl;
			// cout << "b: " << theBoard.checkInput(b) << endl;
			// cout << "c: " << theBoard.checkInput(c) << endl;

			if (agood && bgood && cgood) {
				runCleanCarr = false;
			} else
				cout << "Please input according to the directions!" << endl;
		}
		if (!placeShip(stoi(a), stoi(b), stoi(c), length, type)) {
			cout << "Invalid location try again" << endl;
			runCleanCarr = true;
		} else {
			runCarr = false;
		}
	}
}

void Board::setupOppShip(int length, char type) {
	if (length == 5) {
		placeShip(4, 5, 1, length, type);
	} else if (length == 4) {
		placeShip(1, 1, 2, length, type);
	} else if (length == 3 && type == 'r') {
		placeShip(2, 7, 1, length, type);
	} else if (length == 3 && type == 's') {
		placeShip(7, 0, 2, length, type);
	} else if (length == 2) {
		placeShip(6, 9, 1, length, type);
	}
}

char Board::getSpaceVal(char* b, int x, int y) {
	char* space = b + (sideLength * y) + x;
	return *space;
}

bool Board::getHasShip(char* b, int x, int y) {
	char* space = b + (sideLength * y) + x;
	return (*space != '~');
}

void Board::setSpaceVal(char* b, int x, int y, char type) {
	char* space = b + (sideLength * y) + x;
	*space = type;
}

void Board::printBoard(char* b) {
	for (int y = 0; y < sideLength; y += 1) {
		for (int x = 0; x < sideLength; x += 1) {
			cout << getSpaceVal(b, x, y) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Board::printBoard2() {
	for (int y = 0; y < sideLength; y += 1) {
		for (int x = 0; x < sideLength; x += 1) {
			char* space = data + (sideLength * y) + x;
			cout << *space << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::checkAllType(char* b, char type) {
	for (int y = 0; y < sideLength; y += 1) {
		for (int x = 0; x < sideLength; x += 1) {
			if (getSpaceVal(b, x, y) == type) {
				return true;
			}
		}
	}
	return false;
}

bool Board::allSunk(char* b) {
	for (int y = 0; y < sideLength; y += 1) {
		for (int x = 0; x < sideLength; x += 1) {
			if (getSpaceVal(b, x, y) == 'c' || getSpaceVal(b, x, y) == 'b'
					|| getSpaceVal(b, x, y) == 'r'
					|| getSpaceVal(b, x, y) == 's'
					|| getSpaceVal(b, x, y) == 'd') {
				return false;
			}
		}
	}
	return true;
}

bool Board::sameShot(char* b, int x, int y) {
	return (getSpaceVal(b, x, y) == 'H' || getSpaceVal(b, x, y) == 'M');
}

bool Board::hitOrMiss(char* b, int x, int y) {
	return (getSpaceVal(b, x, y) != '~' && getSpaceVal(b, x, y) != 'M');
}

void Board::updateOppVis(char* bOpp, char* bOppVis, Board* opp, Board* oppVis) {
	for (int y = 0; y < sideLength; y += 1) {
		for (int x = 0; x < sideLength; x += 1) {
			if (opp->getSpaceVal(bOpp, x, y) == 'H') {
				oppVis->setSpaceVal(bOppVis, x, y, 'H');
			}
			if (opp->getSpaceVal(bOpp, x, y) == 'M') {
				oppVis->setSpaceVal(bOppVis, x, y, 'M');
			}
		}
	}
}

void Board::guessLoop(Board* you, Board* opp, Board* oppVis) {

	srand((unsigned) time(0));

	bool play = true;

	int round = 1;

	int guessX = 0;
	int guessY = 0;

	int oppGuessX = 0;
	int oppGuessY = 0;

	while (play) {
		bool oppCanPlay = true;

		cout << "ROUND " << round << endl << endl;

		cout << "Your Board:" << endl;
		printBoard(you->data);
		cout << "Enemy's Board:" << endl;
		printBoard(oppVis->data);
		// printBoard(opp->data);

		bool inputs = true;

		cout << "YOUR TURN" << endl;

		while (inputs) {
			string a;
			string b;

			bool agood = false;
			bool bgood = false;
			bool inputsGood = false;
			bool notSameShot = false;

			cout
					<< "Please input x and y coordinates for your guess (0 to 9 inclusive):"
					<< endl;
			cin >> a;

			if (checkInput(a)) {
				agood = true;
			}

			cin >> b;

			if (checkInput(b)) {
				bgood = true;
			}

			if (agood && bgood) {
				inputsGood = true;
			}

			if (!sameShot(opp->data, stoi(a), stoi(b))) {
				notSameShot = true;
			}

			if (!inputsGood) {
				cout << "Input is invalid. Please try again." << endl;
			}
			else if (!notSameShot) {
				cout
						<< "You wouldn't want to hit the same spot twice, would ya?"
						<< endl;
			}
			else {
				inputs = false;
				guessX = stoi(a);
				guessY = stoi(b);
			}
		}

		char hitType = '@';

		if (hitOrMiss(opp->data, guessX, guessY)) {
			hitType = getSpaceVal(opp->data, guessX, guessY);
			setSpaceVal(opp->data, guessX, guessY, 'H');
			cout << "It's a hit!" << endl;

			if (!checkAllType(opp->data, hitType)) {
				if (hitType == 'c') {
					cout << "You sunk the enemy's carrier!" << endl;
				} else if (hitType == 'b') {
					cout << "You sunk the enemy's battleship!" << endl;
				} else if (hitType == 'r') {
					cout << "You sunk the enemy's cruiser!" << endl;
				} else if (hitType == 's') {
					cout << "You sunk the enemy's submarine!" << endl;
				} else if (hitType == 'd') {
					cout << "You sunk the enemy's destroyer!" << endl;
				}
			}
		} else {
			setSpaceVal(opp->data, guessX, guessY, 'M');
			cout << "It's a miss!" << endl;
		}

		oppVis->updateOppVis(opp->data, oppVis->data, opp, oppVis);

		// cout << "checking if you have won" << endl;
		if (allSunk(opp->data)) {
			cout << "Your Board:" << endl;
			printBoard(you->data);
			cout << "Enemy's Board:" << endl;
			printBoard(oppVis->data);
			cout << "You have sunk all the enemy's ships! YOU WIN!" << endl;
			oppCanPlay = false;
			play = false;
		}

		if (oppCanPlay) {
			cout << "ENEMY'S TURN" << endl;

			char hitTypeOpp = '@';

			bool getRandShot = true;

			while (getRandShot) {
			oppGuessX = rand() % 10;
			// cout << "Enemy guess X: " << oppGuessX << endl;
			oppGuessY = rand() % 10;
			// cout << "Enemy guess Y: " << oppGuessY << endl;
				if (!sameShot(you->data, oppGuessX, oppGuessY)) {
					getRandShot = false;
				}
			}

			if (hitOrMiss(you->data, oppGuessX, oppGuessY)) {
				hitTypeOpp = getSpaceVal(you->data, oppGuessX, oppGuessY);
				setSpaceVal(you->data, oppGuessX, oppGuessY, 'H');
				cout << "It's a hit!" << endl;

				if (!checkAllType(you->data, hitTypeOpp)) {
					if (hitTypeOpp == 'c') {
						cout << "The enemy sunk your carrier!" << endl;
					} else if (hitType == 'b') {
						cout << "The enemy sunk your battleship!" << endl;
					} else if (hitType == 'r') {
						cout << "The enemy sunk your cruiser!" << endl;
					} else if (hitType == 's') {
						cout << "The enemy sunk your submarine!" << endl;
					} else if (hitType == 'd') {
						cout << "The enemy sunk your destroyer!" << endl;
					}
				}
			} else {
				setSpaceVal(you->data, oppGuessX, oppGuessY, 'M');
				cout << "It's a miss!" << endl;
			}

			// cout << "checking if you have lost" << endl;
			if (allSunk(you->data)) {
				cout << "Your Board:" << endl;
				printBoard(you->data);
				cout << "Enemy's Board:" << endl;
				printBoard(oppVis->data);
				cout << "The enemy has sunk all your ships! YOU LOSE!" << endl;
				play = false;
			}
		}
		if (play) {
			// cout << "GOT TO END" << endl;
			round += 1;
		}
	}
}
