#include "Iterator.h"

Iterator::Iterator(Function** ptr) : ptr(ptr) {}

Iterator& Iterator::operator++()
{
    ++(this->ptr);
    return *this;
}

Function** Iterator::operator*()
{
    return this->ptr;
}

bool Iterator::operator==(const Iterator& object)
{
    return this->ptr == object.ptr;
}

bool Iterator::operator!=(const Iterator& object)
{
    return !(*this == object);
}
