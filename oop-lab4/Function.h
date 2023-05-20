#pragma once

#include <iostream>
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