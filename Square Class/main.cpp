//main.cpp file
#include <iostream>
using namespace std;
#include "square.h"

void main() {
	Square s1(2, 2, 5), s2;
	cout << "------------------------" << endl;

	cout << "printing Square s1" << endl;
	s1.PrintSquare(); cout << endl;

	cout << "change s1 to 5,5 values" << endl;
	s1.SetXY(5, 5);
	cout << "printing againe Square s1 (after the change)" << endl;
	s1.PrintSquare(); cout << endl;

	cout << "change s1 length to 20 values" << endl;
	s1.Setlength(20);
	cout << "printing againe Square s1 (after the change)" << endl;
	s1.PrintSquare(); cout << endl;

	cout << "printing s1 Area : " << endl;
	cout << "Area: " << s1.Area() << endl;
	cout << "------------------------" << endl;

	cout << "printing Square s2" << endl;
	s2.PrintSquare(); cout << endl;

	cout << "change s2 to 5,5 values" << endl;
	s2.SetXY(5, 5);
	cout << "printing againe Square s2 (after the change)" << endl;
	s2.PrintSquare(); cout << endl;

	cout << "change s2 length to 20 values" << endl;
	s2.Setlength(20);
	cout << "printing againe Square s2 (after the change)" << endl;
	s2.PrintSquare(); cout << endl;

	cout << "printing s2 Area : " << endl;
	cout << "Area: " << s2.Area() << endl;
	cout << "------------------------" << endl;

	system("pause");
}
