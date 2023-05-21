#pragma once

#include <iostream>
#include <limits>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Function
{
public:
	Function() : lastValue(0.0) {}
	virtual ~Function() {}
	virtual double operator() (double value) = 0;
	virtual Function* clone() const = 0;

protected:
	double lastValue;
};