#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()
//	:_a(1)
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{   
//	A* p = new A[5];
//	delete []p;
//	return 0;
//}
//


//int main()
//{
//	string s1;
//	string s2("Hello World!");
//	cout << s2 << endl;
//
//	for (int i = 0; i < s2.size(); ++i)
//	{
//		cout << s2[i];
//	}
//	cout << endl;
//	return 0;
//}

int main()
{
	string s1("Hello World");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		(*it)--;
		++it;
	}

	cout << endl;

	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;

	for (auto& ch : s1)
	{
		ch++;
	}
	cout << endl;

	//范围for访问
	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}


class Solution {
public:
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int carry = 0;
		string StrRet;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
			int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
			int ret = val1 + val2 + carry;
			carry = ret / 10;
			ret = ret % 10;

			StrRet += ('0' + ret);

			--end1;
			--end2;
		}
		if (carry == 1)
		{
			StrRet += '1';
		}

		reverse(StrRet.begin(), StrRet.end());

		return StrRet;

	}
};