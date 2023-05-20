#include "Arccot.h"

#define _USE_MATH_DEFINES
#include <cmath>

Arccot::Arccot() : Function() {}

Arccot::~Arccot() {}

double Arccot::operator()(double value)
{
	this->lastValue = M_PI_2 - atan(value);
	return this->lastValue;
}

Function* Arccot::clone() const
{
	return new Arccot(*this);
}

bool Arccot::operator==(const Arccot& object)
{
	return this->lastValue == object.lastValue;
}

bool Arccot::operator!=(const Arccot& object)
{
	return !(this == &object);
}

Arccot& Arccot::operator=(const Arccot& object)
{
	if (this != &object) this->lastValue = object.lastValue;
	return *this;
}
