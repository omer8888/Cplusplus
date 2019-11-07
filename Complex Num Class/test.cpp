#include <iostream>
using namespace std;
#include "complex.h"

void main()
{
	Complex c1(1.0, -4.0);
	Complex c2(15.0, 1.0);
	Complex c3 = c1 + c2;

	c2 += c1;
	cout << c2;

	c2 *= c1;
	c2 /= c1;
	c2 -= c1;
	c3 = c1 + c2;
	c3 = c1 - c2;
	c3 = c1 * c2;
	c3 = c1 / c2;
	double d = 5.0;
	c2 = c1 * d;
	c2 = c1 * d;
	c2 = c1 / d;


}
