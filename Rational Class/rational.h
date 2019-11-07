#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational
{
private:
	int numerator;//����
	int  denominator;//����

public:
	friend ostream& operator<<(ostream & os,const Rational &r);//����� ������
	friend istream& operator>>(istream & in, Rational &r);//����� ������

	Rational(int numerator=1 , int denominator=1);//����, �� ������ ����� �� ���� ����� 0

	int Get_numerator() const { return numerator; }
	int Get_denominator() const { return denominator; }
	void Set_numerator(int n1);
	void Set_denominator(int d1);
	void FixRational();
	void PrintRational() const;//����� �� ����

	 Rational operator+(const Rational& other) const; //����� �����
	 Rational operator-(const Rational& other) const; //����� �����
	 Rational operator*(const Rational& other) const; //��� �����
	 Rational operator/(const Rational& other) const;//����� �����
	 Rational operator--() const; //����� �� ���, ��� ���� �������

};

#endif