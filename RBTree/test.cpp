#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

#include "RBTree.h"

//int main()
//{
//	int a[] = { 1111,22222, 8888888, 33333,44444, 777777,6666666 };
//	RBTree<int, int> rbt;
//	for (const int& e : a)
//	{
//		if (e == 33333)
//		{
//			int x = 0;
//		}
//		rbt.Insert(make_pair(e, e));
//		cout << "Insert:" << e << "->" << rbt.Isbalance() << endl;
//	}
//
//	return 0;
//}

int main()
{
	RBTree<int, int> rbt;
	vector<int> v;
	int N = 10000;
	srand(time(0));
	for (int i = 0; i < N; ++i)
	{
		v.push_back(rand());
	}
	for (const int& e : v)
	{
		rbt.Insert(make_pair(e, e));
		cout << "Insert:" << e << "->" << rbt.Isbalance() << endl;
	}
	cout << rbt.Isbalance() << endl;

	return 0;
}