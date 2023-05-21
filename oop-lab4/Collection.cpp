#include "Collection.h"

Collection::Collection() : ptr(nullptr), size(0) {}

Collection::Collection(int size)
{
	this->size = size;
	this->ptr = new Function * [size];
	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = nullptr;
	}
}

Collection::Collection(const Collection& object)
{
	this->size = object.size;
	this->ptr = new Function * [size];
	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = object.ptr[i]->clone();
	}
}

Collection::~Collection()
{
	for (int i = 0; i < this->size; i++)
	{
		delete this->ptr[i];
	}
	delete[] this->ptr;
}

int Collection::getSize()
{
	return this->size;
}

Function*& Collection::operator[](int index)
{
	if (index < 0 || index >= size) throw("Выход за пределы массива!");
	return ptr[index];
}

Collection& Collection::operator=(const Collection& object)
{
	if (this != &object)
	{
		for (int i = 0; i < this->size; i++)
		{
			delete this->ptr[i];
		}
		delete[] this->ptr;
		this->size = object.size;
		this->ptr = new Function * [size];
		for (int i = 0; i < this->size; i++)
		{
			this->ptr[i]= object.ptr[i]->clone();
		}
	}
	return *this;
}

void Collection::pushBack(const Function* object)
{
	Function** newPtr = new Function * [this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		newPtr[i] = this->ptr[i];
	}
	newPtr[this->size++] = object->clone();
	this->ptr = newPtr;
	return;
}

void Collection::insert(const Function* object, int index)
{
	if (index < 0 || index >= size) throw("Выход за пределы массива!");

	Function** newPtr = new Function * [this->size + 1];
	for (int i = 0; i < index; i++)
	{
		newPtr[i] = this->ptr[i];
	}
	newPtr[index] = object->clone();
	for (int i = index; i < this->size; i++)
	{
		newPtr[i + 1] = this->ptr[i];
	}
	this->ptr = newPtr;
	++this->size;
	return;
}

void Collection::truncation(int index)
{
	if (index < 0 || index >= size) throw("Выход за пределы массива!");

	for (int i = index; i < this->size; i++)
	{
		delete this->ptr[i];
	}
	this->size = index;
	return;
}

void Collection::erase(int index)
{
	if (index < 0 || index >= size) throw("Выход за пределы массива!");

	Function** newPtr = new Function * [this->size - 1];
	for (int i = 0; i < index; i++)
	{
		newPtr[i] = this->ptr[i];
	}
	for (int i = index + 1; i < this->size; i++)
	{
		newPtr[i - 1] = this->ptr[i];
	}
	this->ptr = newPtr;
	--this->size;
	return;
}

Iterator Collection::begin()
{
	return Iterator(this->ptr);
}

Iterator Collection::end()
{
	return Iterator(this->ptr + this->size);
}
