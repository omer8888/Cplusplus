////**************************
////**** BY OMER NAIM ********
////**************************

#include<iostream>
using namespace std;


int power(int x, int y);
int rec_array_sum(int *arr, int size);


void main()
{
	/*cout << power(5, 2)<<endl;*/

	int arr[] = { 1,2,3,4,5,6 };
	cout << rec_array_sum(arr, 6) << endl;

	system("pause");
}

int power(int x, int y)
{
	int temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp * temp;
	else
		return temp * temp*x;
}

int rec_array_sum(int *arr, int size)
{
	if (size == 0)
		return 0;
	else
		return rec_array_sum(arr, size - 1) + arr[size-1];
}



