/*
 * Tests.cpp
 *
 *  Created on: Mar 1, 2022
 *      Author: crua8
 */

#include "Tests.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::testAll(int argc, char* argv[]) {

	inputFilePath = argv[1];
	outputFilePath = argv[2];

	Room* room = new Room(inputFilePath, outputFilePath);

	room -> numRooms = room -> findNumRooms();
	room -> createMatrix();

	bool allOK = false;

	bool testGoToLine = false;
	bool testFindNumRooms = false;
	bool testadjList = false;
	bool testGetValue = false;
	bool testRoomData = false;
	bool testCreateMatrix = false;
	bool testCleanAllRoom = false;
	bool testAddToPath = false;
	bool testClean = false;

	cout << "Testing all functions in Vacuum:" << endl;

	// TEST goToLine //

	fstream inputFile;

	inputFile.open(inputFilePath);

	room -> goToLine(inputFile, 5);

	string line;

	getline(inputFile, line);

	if (line == "0") {
		cout << "goToLine passed its test!" << endl;
		testGoToLine = true;
	} else {
		cout << "goToLine failed its test!" << endl;
	}

	// TEST findNumRooms //

	int numRooms = room -> findNumRooms();

	if (numRooms == 15) {
		cout << "findNumRooms passed its test!" << endl;
		testFindNumRooms = true;
	} else {
		cout << "findNumRooms failed its test!" << endl;
	}

	// TEST adjList //

	list<int> expected;
	expected.push_back(0);
	expected.push_back(11);
	expected.push_back(12);

	list<int> actual = room -> adjList(13);

	if (expected == actual) {
		cout << "adjList passed its test!" << endl;
		testadjList = true;
	} else {
		cout << "adjList failed its test!" << endl;
	}

	// TEST getValue //

	int val = room -> getValue(13, 12);

	if (val == 1) {
		cout << "getValue passed its test!" << endl;
		testGetValue = true;
	} else {
		cout << "getValue failed its test!" << endl;
	}

	// TEST roomData //

	int edge = room -> roomData(11, 13);

	if (edge == 1) {
		cout << "roomData passed its test!" << endl;
		testRoomData = true;
	} else {
		cout << "roomData failed its test!" << endl;
	}

	// TEST createMatrix //

	int topLeft = room -> getValue(0, 0);
	int bottomRight = room -> getValue(14, 14);

	if (topLeft == 0 && bottomRight == 0) {
		cout << "createMatrix passed its test!" << endl;
		testCreateMatrix = true;
	} else {
		cout << "createMatrix failed its test!" << endl;
	}

	// TEST cleanAllRoom //

	room -> cleanAllRoom(13);

	int room0Ref = room -> getValue(0, 13);
	int room11Ref = room -> getValue(11, 13);
	int room12Ref = room -> getValue(12, 13);

	if (room0Ref == 2 && room11Ref == 2 && room12Ref == 2) {
		cout << "cleanAllRoom passed its test!" << endl;
		testCleanAllRoom = true;
	} else {
		cout << "cleanAllRoom failed its test!" << endl;
	}

	// TEST addToPath //

	room -> cleanPath = "";

	room -> addToPath(6);

	string path = room -> cleanPath;

	if (path == "6 ") {
		cout << "addToPath passed its test!" << endl;
		testAddToPath = true;
	} else {
		cout << "addToPath failed its test!" << endl;
	}

	// TEST clean //

	room -> cleanPath = "";

	room -> clean(0);

	string fullPath = room -> cleanPath;

	if (fullPath == "0 1 2 3 4 5 6 7 8 9 10 14 ") {
		cout << "clean passed its test!" << endl;
		testClean = true;
	} else {
		cout << "clean failed its test!" << endl;
	}

	// Have ALL tests passed? //

	if (testGoToLine && testFindNumRooms && testadjList && testGetValue
			&& testRoomData && testCreateMatrix && testCleanAllRoom
			&& testAddToPath && testClean) {
		allOK = true;
	}

	delete room;

	return allOK;
}
