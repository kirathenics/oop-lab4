#pragma once

#include "Function.h"

class Arctan : public Function
{
public:
	Arctan();
	~Arctan() override;

	double operator() (double value) override;
	Function* clone() const override;
	bool operator== (const Arctan& object);
	bool operator!= (const Arctan& object);
	Arctan& operator= (const Arctan& object);
};
