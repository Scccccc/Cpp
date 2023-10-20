#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

#include "AVLtree.h"

int main()
{
	////int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//AVLTree<int, int> avl;

	//for (int& e : a)
	//{
	//	if (e == 14)
	//	{
	//		int x = 0;
	//	}

	//	avl.Insert(make_pair(e, e));
	//	cout << "Insert:" << e << "->" << avl.Isbalance() << endl;
	//}
	//cout << endl;

	
	AVLTree<int, int> avl;
	vector<int> v;
	int N = 10000;
	v.reserve(N);
	srand(time(0));
	for (int i = 0; i < N; ++i)
	{
		v.push_back(rand());
	}

	for (const auto& e : v)
	{
		avl.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << avl.Isbalance() << endl;
	}
	cout<< avl.Isbalance() << endl;


	return 0;
}