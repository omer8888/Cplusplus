#include <iostream>
using namespace std;
#include "rational.h"

void main()
{
	Rational r1(2,2), r2(3,3);
	Rational r3=r2-r1;
	cout<<r3<<endl;
	r3.FixRational();
	cout<<r3<<endl;





}
