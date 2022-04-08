/*
 * tests.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

bool tests();

bool testLoad();
bool testIsValid();
bool testIsEligible();
bool testSettle();
bool testSavePayload();
bool testPrintList();

bool testValue();
bool testSwap();
bool testReturn();

bool testpitch();

#endif /* TESTS_H_ */
