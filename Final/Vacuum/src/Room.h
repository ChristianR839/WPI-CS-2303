/*
 * Room.h
 *
 *  Created on: Mar 2, 2022
 *      Author: crua8
 */

#ifndef ROOM_H_
#define ROOM_H_

#include "Production.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <limits>
#include <list>

using namespace std;

class Room {
private:
	// Production* production;
public:
	int numRooms;
	int* floor;

	stack<int> stack;

	string cleanPath;

	char* inputFilePath;
	char* outputFilePath;

	Room(char* inputPath, char* outputPath);
	virtual ~Room();

	fstream& goToLine(fstream& file, unsigned int num);
	int findNumRooms();
	list<int> adjList(int room);
	int getValue(int room, int adj);
	int roomData(int room, int adj);
	void createMatrix();
	void cleanAllRoom(int roomToClean);
	void addToPath(int room);
	void clean(int room);
};

#endif /* ROOM_H_ */
