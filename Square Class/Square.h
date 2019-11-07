
#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
	Square() :x(0), y(0), length(0) {};
	Square(double, double, double);

	void SetXY(double, double);
	void Setlength(double);
	double GetX() const;
	double GetY() const;
	double Getlength() const;
	void PrintSquare() const;
	double Area() const;

private:
	double x, y;
	double length;
};


#endif

