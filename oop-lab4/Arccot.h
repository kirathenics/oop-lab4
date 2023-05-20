#pragma once

#pragma once

#include "Function.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Arccot : public Function
{
public:
	Arccot();
	~Arccot() override;

	double operator() (double value) override;
	virtual Function* clone() const override;
	bool operator== (const Arccot& object);
	bool operator!= (const Arccot& object);
	Arccot& operator= (const Arccot& object);
};