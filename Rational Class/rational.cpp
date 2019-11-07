#include "rational.h"
#include <iostream>
using namespace std;

	ostream& operator<<(ostream & os,const Rational &r) //����� ������
	{
	os<<"("<<r.numerator<<"/"<<r.denominator<<")"<<endl;
	return os;
	}
	
	istream& operator>>(istream & in, Rational &r) //����� ������
	{
		in>>r.numerator>>r.denominator;
		return in;
	}

	Rational::Rational(int numerator , int denominator):numerator(numerator) ,denominator(denominator) 
	{//����, �� ������ ����� �� ���� ����� 0
		if (numerator !=0)
		{
			this->numerator=numerator;
			this->denominator=denominator;
		}
		else
		{
			this->numerator=NULL;
			this->denominator=NULL;
			cout<<"ERROR, zero in the denominator"<<endl;
		}
	
	};

	 void Rational::FixRational() //���� ������ ������ �� ������ �����
	 {
		 if(denominator%numerator==0)
		 {
			 this->denominator=denominator/numerator;
			 this->numerator=1;
		 }
		 if(denominator==0)
		 {
			this->numerator=NULL;
			this->denominator=NULL;
			cout<<"ERROR, zero in the denominator"<<endl;
		 }
	 }

	 void Rational::PrintRational() const //����� ����� �� ������� ���� �������
	 {
		 cout<<denominator<<""<<numerator<<endl;
	 }

	Rational Rational::operator+(const Rational& other) const //����� �����
	 {
		 Rational r1 (numerator+other.numerator , denominator+other.denominator);
		 r1.FixRational(); //����� ������ ������ �� ���� 0
		 return r1;
	 }

	Rational Rational::operator-(const Rational& other) const //����� �����
	 {
		 Rational r1 (numerator-other.numerator,denominator-other.denominator);
		 r1.FixRational(); //����� ������ ������ �� ���� 0
		 return r1;
	 }

	
	 Rational Rational::operator*(const Rational& other) const //��� �����
	 {
		 Rational r1(numerator*other.numerator,denominator*other.denominator);
		 r1.FixRational(); //����� ������ ������ �� ���� 0
		 return r1;
	 }

	 Rational Rational::operator/(const Rational& other) const//����� �����
	 {
		 Rational r1(numerator/other.numerator,denominator/other.denominator);
		 r1.FixRational(); //����� ������ ������ �� ���� 0
		 return r1;
	 }

	 Rational Rational::operator--() const //����� �� ���, ��� ���� �������
	 {
		 Rational r1(denominator,numerator);
		 r1.FixRational(); //����� ������ ������ �� ���� 0
		 return r1;
	 }


