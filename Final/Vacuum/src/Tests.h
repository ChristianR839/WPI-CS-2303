/*
 * Tests.h
 *
 *  Created on: Mar 1, 2022
 *      Author: crua8
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Room.h"

using namespace std;

class Tests {
public:
	Tests();
	virtual ~Tests();

	char* inputFilePath;
	char* outputFilePath;

	bool testAll(int argc, char* argv[]);
};

#endif /* TESTS_H_ */
