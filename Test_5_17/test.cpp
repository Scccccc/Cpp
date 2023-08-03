#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	string url("https://legacy.cplusplus.com/");
//	string sub1(url, 0, 5);
//	string sub2(url, 8, 20);
//	cout << sub1 << endl;
//	cout << sub2 << endl;
//	return 0;
//}
//
int main()
{
	int x = 0;
	cin >> x;
	string xstr;
	while (x)
	{
		int val = x % 10;
		xstr += '0' + val;
		x /= 10;
	}
	return 0;
}