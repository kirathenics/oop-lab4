#pragma once

#include "Function.h"

class Collection
{
public:
	Collection();
	Collection(int size);
	Collection(const Collection& object);
	~Collection();

	int getSize();
	Function*& operator[] (int index);
	Collection& operator= (const Collection& object);
	void pushBack(const Function* object);
	void insert(const Function* object, int index);
	void truncation(int index);
	void erase(int index);
	//Iterator begin();
	//Iterator end();

private:
	Function** ptr;
	int size;
};