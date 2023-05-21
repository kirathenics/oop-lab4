#include "Arctan.h"
#include "Arccot.h"
#include "Derivative.h"
#include "Collection.h"

int main()
{
	Arctan test;
	Arccot test1;
	cout << test(2) << endl;
	cout << test1(2) << endl;
	Derivative ptr(&test);

	cout << ptr(2) << endl;
	ptr = new Derivative(&test1);
	cout << ptr(2) << endl;

	Collection col(3);

	return 0;
}