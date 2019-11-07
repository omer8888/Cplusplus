//#include <iostream>
//using namespace std;
//
//
//
//long long ToBinary(int num)
//{
//	long long new_num = 0, save = 1, rem = 0;
//
//	while (num != 0)
//	{
//		rem = num % 2;
//		num = num / 2;
//		new_num = new_num + rem * save;
//		save = save * 10;
//	}
//	return new_num;
//}
//
//
//int solution(int N) {
//	// write your code in C++14 (g++ 6.2.0)
//	int count = 0, flag = 0, max = 0;
//	long long B = ToBinary(N);
//
//	while (B % 10 == 0) //deleting rightest first zeros
//	{
//		B = B / 10;
//	}
//
//	while (B > 1) //cus its the minimal gup
//	{
//		if ((B % 10 == 1) && ((B/10)%10 == 0))
//		{
//			flag = 1;
//			while ((B / 10)%10 == 0)
//			{
//				B = B / 10;
//				count++;
//			}
//			if (count > max)
//			{
//				max = count;
//			}
//			count = 0;
//			flag = 0;
//		}
//		else
//		{
//			B = B / 10;
//		}
//	}
//	return max;
//
//}
//
//
//int main() {
//	int num=solution(1041);
//	cout << num;
//	system("pause");
//}