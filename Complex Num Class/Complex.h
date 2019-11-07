#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double Real;
	double Imagin;
public:
	Complex(double Real = 0, double Imagin = 0) :Real(Real), Imagin(Imagin) {};//брай

	double GetReal() const;
	double GetImagin() const;
	void SetReal(double Real);
	void SetImagin(double Imagin);

	Complex operator+(const Complex& other) const;
	void operator+=(const Complex & other);
	Complex operator+(const double num) const;

	Complex operator-(const Complex& other) const;
	void operator-=(const Complex & other);
	Complex operator-(double num)const;

	Complex operator*(const Complex& other) const;
	void operator*=(const Complex & other);
	Complex operator*(double num)const;;

	Complex operator/(const Complex& other) const;
	void operator/=(const Complex & other);
	Complex operator/(double num)const;

	friend ostream & operator<<(ostream &, const Complex &);
};

//Complex c1( 1.0, -4.0 );
//Complex c2( 15.0, 1.0 );
//Complex c3 = c1 + c2;
//c2 += c1;
//c2 *= c1;
//c2 /= c1;
//c2 -= c1;
//c3 = c1 + c2;
//c3 = c1 - c2;
//c3 = c1 * c2;
//c3 = c1 / c2;
//double d=5.0;
//c2=d*c1;
//c2=c1*d;
//c2=d/c1;
//c2=c1/d;

#endif
