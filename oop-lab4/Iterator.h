#pragma once

#include "Function.h"

class Iterator
{
public:
	Iterator(Function** ptr);
	Iterator& operator ++ ();
	Function** operator * ();
	bool operator == (const Iterator& object);
	bool operator != (const Iterator& object);
	
private:
	Function** ptr;
};

