/*
 * Control.h
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <iostream>

using namespace std;

class Control {
public:
	Control();
	Control(int,int,int,bool);
	~Control();
	void printToString()
	{
		cout << beginTime << "," << duration << "," << severity << endl;
	}
	bool operator==(const Control &other) const;
	bool operator!=(const Control &other) const;
	bool operator<(const Control &other) const;
	bool operator>(const Control &other) const;

	int index;
	int beginTime;//0-1,000,000
	int duration;//0-1,000,000
	int severity;//0-100,000
	bool active;
	bool compareTime;
};

#endif /* CONTROL_H_ */
