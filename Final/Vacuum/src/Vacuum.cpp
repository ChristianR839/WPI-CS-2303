//============================================================================
// Name        : Vacuum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Tests.h"
#include "Production.h"
#include "Room.h"

using namespace std;

int main(int argc, char* argv[]) {

	Tests* tests = new Tests();

	if (tests -> testAll(argc, argv)) {
		cout << "All tests have passed!" << endl << endl;
		cout << "Running program..." << endl;

		Production* production = new Production();

		production -> process(argc, argv);

		delete production;

		cout << "Program finished!" << endl;
	} else {
		cout << "Not every test passed!" << endl;
	}

	delete tests;
}
