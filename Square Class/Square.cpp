//Square.cpp file
#include "square.h"
#include <iostream>
using namespace std;

Square::Square(double x, double y, double length)
	:length(length), x(x), y(y) {};


void Square::PrintSquare() const {
	cout << "([" << x << "," << y << "]," << length << ")";
}

void Square::SetXY(double x1, double y1)
{
	x = x1;
	y = y1;
};

void Square::Setlength(double length1)
{
	length = length1;
}

double Square::GetX() const
{
	return x;
}

double Square::GetY() const
{
	return y;
}

double Square::Getlength() const
{
	return length;
}


double Square::Area() const
{
	return (x*y);
}

