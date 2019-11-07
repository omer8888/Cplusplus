////**************************
////**** BY OMER NAIM ********
////**************************

#include <iostream>
using namespace std;

int fibonacci(int num);
int fibonacci_rec(int num);
void swap(int *x, int *y);


void main()
{
	int num;
	cout << "enter index to the fibonnacci: ";
	cin >> num;
	cout << "(normal) the fibonnacci num is: " << fibonacci(num) << endl;
	cout << "(rec) the fibonnacci num is: " << fibonacci(num) << endl;


	system("pause");
}


int fibonacci(int num)
{
	int a = 0, b = 1, c;
	if (num < 2)
		return num;
	for (int i = 2; i <= num; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int fibonacci_rec(int num)
{
	if (num < 2)
		return num;
	else
		return fibonacci_rec(num - 1) + fibonacci_rec(num - 2);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


