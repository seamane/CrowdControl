/*
 * Control.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#include "Control.h"


Control::Control()
{
	beginTime = -1;
	duration = 0;
	severity = 0;
	active = false;
	index = -1;
}

Control::Control(int b, int d, int s) {
	beginTime = b;
	duration = d;
	severity = s;
	active = false;

	index = -1;
}

Control::~Control() {
}

bool Control::operator==(const Control &other) const
{
	return this->active == other.active
			&& this->duration == other.duration
			&& this->severity == other.severity;
}

bool Control::operator!=(const Control &other) const
{
	return this->active != other.active
			|| this->duration != other.duration
			|| this->severity != other.severity;
}
