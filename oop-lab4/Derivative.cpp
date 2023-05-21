#include "Derivative.h"

Derivative::Derivative() : Function(), ptr(nullptr) {}

Derivative::Derivative(Function* ptr) : Function(), ptr(ptr) {}

Derivative::~Derivative() {}

double Derivative::operator()(double value)
{
	this->lastValue = (ptr->operator()(value + step) - ptr->operator()(value - step)) / (2 * step);
	return this->lastValue;
}

Function* Derivative::clone() const
{
	return new Derivative(*this);
}

bool Derivative::operator==(const Derivative& object)
{
	return fabs(this->lastValue - object.lastValue) < numeric_limits<double>::epsilon();
}

bool Derivative::operator!=(const Derivative& object)
{
	return !(this == &object);
}

Derivative& Derivative::operator=(const Derivative& object)
{
	if (this != &object)
	{
		this->ptr = object.ptr;
		this->lastValue = object.lastValue;
	}
	return *this;
}
