#include "rational.h"
#include <iostream>
using namespace std;

	ostream& operator<<(ostream & os,const Rational &r) //הדפסה מקוצרת
	{
	os<<"("<<r.numerator<<"/"<<r.denominator<<")"<<endl;
	return os;
	}
	
	istream& operator>>(istream & in, Rational &r) //קליטה מקוצרת
	{
		in>>r.numerator>>r.denominator;
		return in;
	}

	Rational::Rational(int numerator , int denominator):numerator(numerator) ,denominator(denominator) 
	{//בנאי, יש להתחשב שמונה לא יכול להיות 0
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

	 void Rational::FixRational() //בודק אפשרות צימצום או אפשרות שגיאה
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

	 void Rational::PrintRational() const //הדפסה רגילה של אובייקט מסוג רציונלי
	 {
		 cout<<denominator<<""<<numerator<<endl;
	 }

	Rational Rational::operator+(const Rational& other) const //חיבור שברים
	 {
		 Rational r1 (numerator+other.numerator , denominator+other.denominator);
		 r1.FixRational(); //בדיקת אפשרות צימצום או מכנה 0
		 return r1;
	 }

	Rational Rational::operator-(const Rational& other) const //חיסור שברים
	 {
		 Rational r1 (numerator-other.numerator,denominator-other.denominator);
		 r1.FixRational(); //בדיקת אפשרות צימצום או מכנה 0
		 return r1;
	 }

	
	 Rational Rational::operator*(const Rational& other) const //כפל שברים
	 {
		 Rational r1(numerator*other.numerator,denominator*other.denominator);
		 r1.FixRational(); //בדיקת אפשרות צימצום או מכנה 0
		 return r1;
	 }

	 Rational Rational::operator/(const Rational& other) const//חילוק שברים
	 {
		 Rational r1(numerator/other.numerator,denominator/other.denominator);
		 r1.FixRational(); //בדיקת אפשרות צימצום או מכנה 0
		 return r1;
	 }

	 Rational Rational::operator--() const //היפוך של שבר, סתם סימן שהמצאתי
	 {
		 Rational r1(denominator,numerator);
		 r1.FixRational(); //בדיקת אפשרות צימצום או מכנה 0
		 return r1;
	 }


