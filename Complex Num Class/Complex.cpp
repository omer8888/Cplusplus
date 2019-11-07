#include <iostream>
using namespace std;
#include "complex.h"

double Complex::GetReal() const
{
	return Real;
}

double Complex::GetImagin() const
{
	return Imagin;
}

void Complex::SetReal(double Real)
{
	this->Real = Real;
}

void Complex::SetImagin(double Imagin)
{
	this->Imagin = Imagin;
}

//---------------------------------------------------------------
Complex Complex::operator+(const Complex & other)const
{//����� ��������� ������ ��������
	Complex c1(Real + other.Real, Imagin + other.Imagin);
	return c1;
}

void Complex::operator+=(const Complex & other)
{//������ ������� ������ ������� ���
	Real += other.Real;
	Imagin += other.Imagin;
}

Complex Complex::operator+(double num)const
{//����� ������� �� ���� ������ �������� ���
	return Complex(Real + num, Imagin + num);
}

//--------------------------------------------------------------

Complex Complex::operator-(const Complex & other)const
{
	Complex c1(Real - other.Real, Imagin - other.Imagin);
	return c1;
}
void Complex::operator-=(const Complex & other)
{//������ ������� ������ ������� ���
	Real -= other.Real;
	Imagin -= other.Imagin;
}

Complex Complex::operator-(double num)const
{//����� ������� �� ���� ������ �������� ���
	return Complex(Real - num, Imagin - num);
}

//--------------------------------------------------------------

Complex Complex::operator*(const Complex & other)const
{
	Complex c1(Real*other.Real, Imagin*other.Imagin);
	return c1;
}
void Complex::operator*=(const Complex & other)
{//������ ������� ������ ������� ���
	Real *= other.Real;
	Imagin *= other.Imagin;
}

Complex Complex::operator*(double num)const
{//����� ������� �� ���� ������ �������� ���
	return Complex(Real*num, Imagin*num);
}

//--------------------------------------------------------------

Complex Complex::operator/(const Complex & other)const
{
	Complex c1(Real / other.Real, Imagin / other.Imagin);
	return c1;
}
void Complex::operator/=(const Complex & other)
{//������ ������� ������ ������� ���
	Real /= other.Real;
	Imagin /= other.Imagin;
}

Complex Complex::operator/(double num)const
{//����� ������� �� ���� ������ �������� ���
	return Complex(Real / num, Imagin / num);
}

//-------------------------------------------------------------

ostream &operator<<(ostream &print, const Complex &c)
{
	print << c.GetReal();
	if (c.GetImagin() > 0)
		print << " + ";
	print << c.GetImagin() << "i";
	return print;
}

