////**************************
////**** BY OMER NAIM ********
////**************************

#include <iostream>
#include <array>

using namespace std;

void change_arr(int *arr, int size);
void change_arr2(int **arr, int size);
void print_arr(int * arr, int size);
bool isPalindrom(int *arr, int size);
void binary_Search(int * arr, int size, int key);
void binary_Serch_rec(int * arr, int size, int key, int left, int right);
void swap(int *x, int *y);  //int arr only like this (&arr[0],&arr[1])
void swap2(int &x, int &y); //in arr values (arr[0],arr[1])
void bubbleSort(int *arr, int n);
void revers_array(int *arr, int size);
void revers_array_rec(int *arr, int left, int right);
int search_for_extra(int* arr1, int size1, int* arr2, int size2);
void pair_sum_is_Closest_to_k(int * arr, int size, int k);
void missing_in_sorted(int *arr, int size);




void main()
{
	//int x = 1;
	//int y = 9;
	//cout << "x= " << x << "  y= " << y << endl;
	//swap2(x, y); //swap(x,y) will do the same swap
	//cout << "x= " << x << "  y= " << y << endl;

	//int* arr = new int[4];              //dynamic allocation array
	//change_arr(arr, 4);
	//print_arr(arr, 4);


	//int arr3[4] = { 1,1,1,1 };          //normal array
	//change_arr(arr3, 4);
	//print_arr(arr3, 4);
	//


	//int arr2[] = { 1,2,2,1 };
	//cout << "is the array palindron? " << (isPalindrom(arr2, 4) ? "YES" : "NO");


	//int arr2[] = { 0,2,4,9,10,13,44,50 };
	//binary_Search(arr2, 8, 2);
	//binary_Search(arr2, 8, 9);
	//binary_Search(arr2, 8, 44);
	//binary_Search(arr2, 8, 50);
	//binary_Search(arr2, 8, 51);


	//int arr4[] = { 3,20,17,55,4,9,10 };
	//print_arr(arr4, 7);
	//bubbleSort(arr4, 7);
	//print_arr(arr4, 7);

	//int arr5[] = { 3,20,17,55,4,9,10 };
	//print_arr(arr5, 7);
	//revers_array(arr5, 7);
	//print_arr(arr5, 7);

	//int arr6[] = { 3,20,17,55,4,9,10 };
	//print_arr(arr6, 7);
	//revers_array_rec(arr6,0, 7);
	//print_arr(arr6, 7);

	//int arr8[] = { 1,2,3,4,5,6,7,8 };
	//int arr9[] = { 1,2,3,4,5,6,7,8 };
	//cout<<search_for_extra(arr8, 7, arr9, 8)<<endl;

	//int arr9[] = { 12,33,42,51,68,70,80 };
	//pair_sum_is_Closest_to_k(arr9, 7, 54);

	/*int arr10[] = { 1,2,4,5,6,7,8 };
	missing_in_sorted(arr10, 7);*/

	
	//int arr11[] = { 0,2,4,9,10,13,44,50 };
	//binary_Serch_rec(arr11, 8, 0, 0, 7);
	//binary_Serch_rec(arr11, 8, 2, 0, 7);
	//binary_Serch_rec(arr11, 8, 9, 0, 7);
	//binary_Serch_rec(arr11, 8, 44, 0, 7);
	//binary_Serch_rec(arr11, 8, 50, 0, 7);

	system("pause");
}


void change_arr(int *arr, int size) 
{//update all values of arr to 2 
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = 2;
	}
}

void change_arr2(int **arr, int size)
{//another metode to update all values of arr to 2 
	int i;
	for (i = 0; i < size; i++)
	{
		(*arr)[i] = 2;
	}
}

void print_arr(int  *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout <<endl;
}

bool isPalindrom(int *arr, int size)
{		//cheaking if the arr is a palindrom
	int left = 0, right= size-1;
	while (left < right)
	{
		if (arr[left] != arr[right])
			return false;
		left++;
		right--;
	}
	return true;
}

void binary_Search(int * arr,int size, int key)
{			//finding k index in the array in (log n)
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == key)
		{
			cout << "the key: " << key << ", is in the array in index: " << mid << endl;
			return;
		}
		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid-1;
	}
	cout << "the key isnt in the array"<<endl;
	
}

void binary_Serch_rec(int * arr, int size, int key, int left, int right)
{
	int mid = (left + right) / 2;

	if (arr[mid] == key)
	{
		cout << "the key: " << key << ", is in the array in index: " << mid << endl;
		return;
	}
	if (left > right)
	{
		cout << "the key isnt in the array" << endl;
		return;
	}

	if (arr[mid] < key)
	{
		left = mid + 1;
		binary_Serch_rec(arr, size, key, left, right);
	}
	else
	{
		right = mid - 1;
		binary_Serch_rec(arr, size, key, left, right);
	}

}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap2(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void bubbleSort(int *arr, int size) //O(n^2) 
{//every run moving the max num to the end,
//than run again to move the secound max to the end-1 place
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)// Last i elements are already in place  
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);//swap2(arr[j], arr[j + 1]);
}

void revers_array(int *arr, int size)
{
	int right = size - 1;
	int left = 0;

	while (left < right)
	{
		swap(&arr[left], &arr[right]);// swap2(arr[left], arr[right]);
		left++;
		right--;
	}

}

void revers_array_rec(int *arr, int left, int right)
{
	if (left >= right)
		return;
	swap(&arr[left], &arr[right]); //swap2(arr[left], arr[right]);
	revers_array_rec(arr,left + 1, right - 1);	
}

int search_for_extra(int* arr1, int size1, int* arr2, int size2)
{//get  2 sorted arrays with same valuse exept 1 value missing in array1
//this func is retuning the missing value in arr1 

//arr2 size is bigger than arr1 size in 1 extra value
//arrays are sorted

	if (arr1[size1 - 1] != arr2[size2 - 1])
		return arr2[size2 - 1];

	int left = 0;
	int right = size1 - 1;
	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr1[mid] == arr2[mid])
		{
			if (arr1[mid+1] > arr2[mid+1]) 
				return arr2[mid+1];
			left = mid + 1;
		}
		else//(arr1[mid] > arr2[mid])
			right = mid;
	}
	return arr2[mid];

}

void pair_sum_is_Closest_to_k(int * arr, int size, int k)
{
	int res_l, res_r;  // To store indexes of result pair 
	int l = 0, r = size - 1, diff = INT_MAX;
							//this is the max dif that can be bitween int nums
	while (r > l)
	{
		if (abs(arr[l] + arr[r] - k) < diff)
		{// Check if this pair is closer than the closest pair so far 
			res_l = l;
			res_r = r;
			diff = abs(arr[l] + arr[r] - k);
		}
		// If this pair has more sum, move to smaller values. 
		if (arr[l] + arr[r] >k)
			r--;
		else // Move to larger values 
			l++;
	}
	cout << " The closest pair is " << arr[res_l] << " and " << arr[res_r]<<endl;
}

void missing_in_sorted(int *arr, int size)
{
	//func get sorted array of N integers from 1 to N 
	//with one number missing 
	//find the missing number Expected time complexity O(logn)
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if ((arr[mid] != mid + 1) && (arr[mid - 1] == mid))
		{
			cout << "the missing num is: " << mid + 1 << endl;
			return;
		}

		if (arr[mid] != mid + 1)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << "there is no missing num "<< endl;
}




