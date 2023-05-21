#include "Arccot.h"

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
	return fabs(this->lastValue - object.lastValue) < numeric_limits<double>::epsilon();
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
