#pragma once

#pragma once

#include "Function.h"

class Arccot : public Function
{
public:
	Arccot();
	~Arccot() override;

	double operator() (double value) override;
	Function* clone() const override;
	bool operator== (const Arccot& object);
	bool operator!= (const Arccot& object);
	Arccot& operator= (const Arccot& object);
};