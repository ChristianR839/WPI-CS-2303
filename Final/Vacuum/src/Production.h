/*
 * Production.h
 *
 *  Created on: Mar 1, 2022
 *      Author: crua8
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include "Room.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <list>

using namespace std;

class Production {
//private:
//	Room* room;
//	Robot* robot;
public:
	char* inputFilePath;
	char* outputFilePath;

	Production();
	virtual ~Production();

	void process(int argc, char* argv[]);
};

#endif /* PRODUCTION_H_ */
