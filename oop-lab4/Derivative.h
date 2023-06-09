#pragma once

#include "Function.h"

class Derivative : public Function
{
public:
	Derivative();
	Derivative(Function* ptr);
	~Derivative() override;

	double operator() (double value) override;
	Function* clone() const override;
	bool operator== (const Derivative& object);
	bool operator!= (const Derivative& object);
	Derivative& operator= (const Derivative& object);

protected:
	Function* ptr;
	double step;
};