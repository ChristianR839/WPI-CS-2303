/*
 * Room.cpp
 *
 *  Created on: Mar 2, 2022
 *      Author: crua8
 */

#include "Room.h"
#include "Production.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <limits>
#include <list>

using namespace std;

string cleanPath;

Room::Room(char* inputPath, char* outputPath) {
	inputFilePath = inputPath;
	outputFilePath = outputPath;
}

Room::~Room() {

}

fstream& Room::goToLine(fstream& file, unsigned int num) {
    file.seekg(ios::beg);
    for(int i = 0; i <= num; i++) { // original subtracted 1 from num
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

int Room::findNumRooms() {
	int numRooms = 0;

	fstream inputFile;

	inputFile.open(inputFilePath);

	if (inputFile.is_open()) {
		string line;
		getline(inputFile, line);
		numRooms = stoi(line); // string to int
		// cout << "Number of rooms: " << line << endl;
	}

	inputFile.close();

	return numRooms;
}

list<int> Room::adjList(int room) {
	fstream inputFile;

	inputFile.open(inputFilePath);

	goToLine(inputFile, room);

	string line;

	getline(inputFile, line);
	// inputFile >> line;

	string numStr;
	int num;

	list<int> roomList;

	// cout << "Room " << room << " adj rooms: ";

	for (char c : line) {
		if (c == ',') {
			num = stoi(numStr);
			// cout << num << ", ";
			roomList.push_back(num);
			numStr = "";
		} else {
			numStr += c;
		}
	}

	num = stoi(numStr);
	// cout << num << endl;
	roomList.push_back(num);

	return roomList;
	// Returns list of all adjacent rooms
}

int Room::getValue(int room, int adj) {
	int* whereOnFloor = floor + (numRooms * room) + adj;
	return *whereOnFloor;
}

int Room::roomData(int room, int adj) {
	// Returns 0 if adj is not adjacent to room, and 1 if it is (uses adjList to compare)

	// if (room == adj) return 1;

	list<int> adjRooms = adjList(room);

	for (int a : adjRooms) {
		if (a == adj) {
			return 1;
		}
	}
	return 0; // If this hits, adj is not an adjacent room
}

void Room::createMatrix() {
	floor = (int*) malloc (numRooms*numRooms*sizeof(int));

	for (int room = 0; room < numRooms; room++) {
		for (int adj = 0; adj < numRooms; adj++) {
			int* whereOnFloor = floor + (numRooms * room) + adj;
			*whereOnFloor = roomData(room, adj);
			// cout << *whereOnFloor << " ";
		}
		// cout << endl;
	}
}

void Room::cleanAllRoom(int roomToClean) {
	// cout << "Cleaned room: " << roomToClean << endl;
	addToPath(roomToClean);
	for (int room = 0; room < numRooms; room++) {
		int* whereOnFloor = floor + (numRooms * room) + roomToClean;
		if (*whereOnFloor == 1) {
			*whereOnFloor = 2;
		}
	}
	stack.push(roomToClean);
}

void Room::addToPath(int room) {
	cleanPath += to_string(room);
	cleanPath += " ";
}

void Room::clean(int room) {

	fstream outputFile;

	outputFile.open(outputFilePath);

	outputFile << "Starting room: " << room << "\n";

	stack.push(room);

	cleanAllRoom(room);
	outputFile << "Cleaned room: " << room << "\n";

	for (int i = stack.size(); i > 1; i = stack.size()) {
		bool allChildEmpty = true;
		// cout << " to room: " << stack.top() << endl;
		for (int j = 1; j <= numRooms; j++) {
			if (getValue(stack.top(), j) == 1) {
				outputFile << "Traveling from room: " << stack.top() << " to room: " << j << "\n";
				allChildEmpty = false;
				// setValue(room, i, 2);
				cleanAllRoom(j);
				outputFile << "Cleaned room: " << j << "\n";
				if (stack.top() != j) {
					stack.push(j);
				}
			}
		}
		if (allChildEmpty) {
			if (stack.top() != 0) {
				outputFile << "Traveling from room: " << stack.top();
			}
			stack.pop();
			if (stack.size() == 1) {
				outputFile << "Cleaning complete!" << "\n";
			} else {
				outputFile << " to room: " << stack.top() << "\n";
			}
		} else {
			allChildEmpty = true;
		}
	}
}
