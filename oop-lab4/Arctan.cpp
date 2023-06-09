#include "Arctan.h"

Arctan::Arctan() : Function() {}

Arctan::~Arctan() {}

double Arctan::operator()(double value)
{
	this->lastValue = atan(value);
	return this->lastValue;
}

Function* Arctan::clone() const
{
	return new Arctan(*this);
}

bool Arctan::operator==(const Arctan& object)
{
	return fabs(this->lastValue - object.lastValue) < numeric_limits<double>::epsilon();
}

bool Arctan::operator!=(const Arctan& object)
{
	return !(*this == object);
}

Arctan& Arctan::operator=(const Arctan& object)
{
	if (this != &object) this->lastValue = object.lastValue;
	return *this;
}
