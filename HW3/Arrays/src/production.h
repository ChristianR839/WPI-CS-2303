/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "Board.h"
#include "LinkedList.h"
#define MAXSTRINGLENGTH (100)

bool production(int argc, char* argv[]);
bool getYesNo(char* query);
void substringExtraction(char* whole, int* results);

int takeAWalk(char*** Bat, char*** first, char*** second, char*** third, char*** home);

#endif /* PRODUCTION_H_ */
