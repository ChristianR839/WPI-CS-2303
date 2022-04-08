/*
 * production.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "production.h"

bool production(int argc, char* argv[])
{
	bool answer = true;

	int nSettlements = -1;//initialize to obviously wrong value

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		fflush(stdout);

		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
			switch(i)
			{
			case 1:
				//supposed to be a positive integer
				nSettlements = (int)strtol(argv[i],NULL, 10);
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);
	}//end of command line arguments

	//now that we have our input,
	//what is to be done:
	Location** board = (Location**) malloc (11*12*sizeof(Location*));
	//init(board, 11,12);
    LLNode* theList = makeEmptyLinkedList();


	for(int s = 0; s<nSettlements; s++)
	{
		int row = -1;
		int col = -1;
		do
		{
			row = rand()%11;
			col = rand()%12;
		}while(!(isValid(board, row, col) && isEligible(board, row, col)));
		settle(board, row, col);
		//remember to make the neighbors INELIGIBLE
		adjustNeighbors(board, row, col);
		Location* x = (Location*)malloc(sizeof(Location));
		x->row = row;
		x->col = col;
		x->occ = SETTLEMENT;
		savePayload(theList, x);
	}

	//print the results
	printHistory(theList);


	return answer;
}

bool getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}

