/*
 * Location.h
 *
 *  Created on: Nov 9, 2021
 *      Author: theresesmith
 */

#ifndef LOCATION_H_
#define LOCATION_H_

typedef enum
{
	INELIGIBLE,
	EMPTY,
	SETTLEMENT,
	CITY
}OccupancyStatus;

typedef struct
{
	int row;
	int col;
	int value;
	int occ;
}Location;

#endif /* LOCATION_H_ */
