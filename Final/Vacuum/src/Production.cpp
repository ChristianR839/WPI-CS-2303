/*
 * Production.cpp
 *
 *  Created on: Mar 1, 2022
 *      Author: crua8
 */

#include "Production.h"
#include "Room.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <list>

using namespace std;

Production::Production() {

}

Production::~Production() {

}

/*
 * Steps for this program:
 * 1.) Read the file input of:
 * 	- The number of rooms
 * 	- The connections between them
 * 2.) Store that data with malloc
 * 3.) Create a path that goes through all the data without retracing its steps
 * 4.) Test everything
 */

void Production::process(int argc, char* argv[]) {
	// cout << "argv[0]: " << argv[0] << endl;
	// cout << "argv[1]: " << argv[1] << endl;
	// cout << "argv[2]: " << argv[2] << endl;

	inputFilePath = argv[1];
	outputFilePath = argv[2];

	Room* room = new Room(inputFilePath, outputFilePath);

	room -> numRooms = room -> findNumRooms();
	room -> createMatrix(); // sets 'floor' equal to the matrix given by the input file
	// cout << "Matrix (size 15) at (Room 13, Adj 12): " << room -> getValue(13, 12) << endl;
	// cout << "Starting room: " << 0 << endl;
	room -> clean(0);

	// room -> outputPath();

	delete room;
}
