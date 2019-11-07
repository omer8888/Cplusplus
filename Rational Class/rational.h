#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational
{
private:
	int numerator;//מונה
	int  denominator;//מכנה

public:
	friend ostream& operator<<(ostream & os,const Rational &r);//הדפסה מקוצרת
	friend istream& operator>>(istream & in, Rational &r);//קליטה מקוצרת

	Rational(int numerator=1 , int denominator=1);//בנאי, יש להתחשב שמכנה לא יכול להיות 0

	int Get_numerator() const { return numerator; }
	int Get_denominator() const { return denominator; }
	void Set_numerator(int n1);
	void Set_denominator(int d1);
	void FixRational();
	void PrintRational() const;//מדפיס את השבר

	 Rational operator+(const Rational& other) const; //חיבור שברים
	 Rational operator-(const Rational& other) const; //חיסור שברים
	 Rational operator*(const Rational& other) const; //כפל שברים
	 Rational operator/(const Rational& other) const;//חילוק שברים
	 Rational operator--() const; //היפוך של שבר, סתם סימן שהמצאתי

};

#endif