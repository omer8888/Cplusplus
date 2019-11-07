//**************************
//**** BY OMER NAIM ********
//**************************
#include <iostream>
#include <string>
#include <string.h>
#include <array>
#include <stdlib.h>

using namespace std;

char Most_commen_letter(char * s);
int arr_max_index(int *arr, int size);
char * capital_letters(char * s);
bool Is_Palindrom1(char * s);
char * Reverse_str(char * s);
int Str2Int(string str);


int main()
{
	string s;    //using string // need to change func inputs to: string s
	cout << "(using string) enter String: ";  //and strlen(s) to s.length()
	getline(cin, s);

	//char str[20];
	//cout << "(using char) enter string: ";
	//gets_s(str);

	//cout << str; // print1
	//puts(str);   // print2

	int num= Str2Int(s);
	cout << num;

	/*cout << "\n the most commen letter (using string) is : " << Most_commen_letter(str) << endl;
	
	cout <<"\n making the string capital letters :  "<< capital_letters(str)<<endl;

	cout << "\nis it palindrom? : " << (Is_Palindrom1(str) ? "yes": "no")<<"\n" << endl;

	cout << "\nrevers the string "<< Reverse_str(str) << endl;
*/
	system("pause");
}

bool Is_Palindrom1(char * s)
{
	int i = 0;
	int j = strlen(s)-1; //cus arr start in index 0 until index size-1

	while (i < j)
	{
		if (s[i]!=s[j])
			return false;
		else
		{
			i++;
			j--;
		}
	}
	return true;
}

char * Reverse_str(char * s)  //by switching bitween first and last untill the middel im reversing the string
{
	int temp;
	int j = strlen(s) - 1;
	for (int i = 0; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

char Most_commen_letter(char * s)
{
	int *arr = new int[26];
	for (int i = 0; i <strlen(s); i++)
	{
		if(s[i]>='A' && s[i]<='Z')
			arr[s[i] - 'A']++;
		else
			if (s[i] >= 'a' && s[i] <= 'z')
				arr[s[i] - 'a']++;
	}
	return char(arr_max_index(arr, 26) + 'a');
}

int arr_max_index(int *arr, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > arr[max])
			max = i;
	}
	return max;
}

char * capital_letters(char * s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i]-'a'+'A';
	}
	return s;
}

int Str2Int(string str)
{
	int result = 0;
	int dig;
	int sigh = 1;
	int start = 0;

	if (str[0] == '-')
	{
		sigh = -1;
		start = 1;
	}

	for (int i = start; i < str.length(); i++)
	{
		dig = 
			- '0';
		result = result * 10 + dig;
	}
	return result*sigh;
}