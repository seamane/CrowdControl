/*
 * Main.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */
#include <string>
#include "CrowdControlSolver.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#define MAX 1000000
#define SEVERITY_MAX 100000

using namespace std;

string generateString(int numEntries)
{
	stringstream toReturn;
	int tempBegin,tempDuration,tempSeverity;
	int prevSeverity = 1;
	int prevBegin = 1;
	while(numEntries != 0)
	{
		tempDuration = rand() % (MAX + 1);//0 - 1,000,000

		if(rand() / RAND_MAX > .9)
		{
			tempSeverity = prevSeverity;
		}
		else
		{
			tempSeverity = (rand() % SEVERITY_MAX) + 1;//0 - 100,000
		}

		if(rand() / RAND_MAX > .9)
		{
			tempBegin = prevBegin;
		}
		else
		{
			tempBegin = rand() % (MAX + 1);//0 - 1,000,000
		}

		toReturn << tempBegin << " " << tempDuration << " " << tempSeverity << "\n";
		prevBegin = tempBegin;
		prevSeverity = tempSeverity;
		--numEntries;
	}

	return toReturn.str();
}

int main()
{
	srand(time(NULL));

	int numEntries;
	cin >> numEntries;

	string input = to_string(numEntries) + "\n" + generateString(numEntries);

	CrowdControlSolver ccs(input,numEntries);
	ccs.run();
	cout << endl << input << endl;
	return 0;
}



