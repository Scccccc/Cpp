#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

#include "BitSet.h"

//int main()
//{
//	//Mycode::bitset<1000> bs;
//
//	//bs.set(1);
//	//bs.set(10);
//	//bs.set(100);
//
//	//cout << bs.test(1) << endl;
//	//cout << bs.test(10) << endl;
//	//cout << bs.test(100) << endl;
//	//cout << bs.test(20) << endl << endl;
//	//bs.reset(1);
//	//bs.reset(10);
//	//bs.reset(100);
//
//	//cout << bs.test(1) << endl;
//	//cout << bs.test(10) << endl;
//	//cout << bs.test(100) << endl;
//	//cout << bs.test(20) << endl << endl;
//
//	//Mycode::bitset<-1> bs2;
// 
// 
// 1. 给定100亿个整数，设计算法找到只出现一次的整数？
//	int arr[] = { 1,1,2,3,4,5,6,5,4,3,6,7 };
//
//	Mycode::twobitset<100> tbs;
//
//	for (auto e : arr)
//	{
//		tbs.set(e);
//	}
//
//	for (auto e : arr)
//	{
//		if (tbs.is_once(e))
//		{
//			cout << e << " ";
//		}
//	}
//	cout << endl;
//
//
//	return 0;
//}

//2. 给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集？
int main()
{
	int arr1[] = { 1,1,2,3,4,5,6,5,4,3,6,7 };
	int arr2[] = { 1,5,4,3,6,7 };
	Mycode::bitset<100> bs1;
	Mycode::bitset<100> bs2;

	for (auto e : arr1)
	{
		bs1.set(e);
	}

	for (auto e : arr2)
	{
		bs2.set(e);
	}

	for (size_t i = 0; i < 12; ++i)
	{
		if (bs1.test(i) && bs2.test(i))
		{
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}