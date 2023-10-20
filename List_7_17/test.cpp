#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

#include "list.h"


//int main()
//{
//	//Mycode::test_list1();
//	srand(time(0));
//	list<int> lt;
//	list<int> lt1;
//
//	vector<int> v;
//	const size_t N = 1000000;
//	v.reserve(N);
//
//	for (size_t i = 0; i < N; ++i)
//	{
//		lt1.push_back(rand());
//		lt.push_back(rand());
//	}
//	int begin1 = clock();
//	//把链表数据拷贝到vector
//	for (auto e : lt1)
//	{
//		v.push_back(e);
//	}
//	//排序
//	sort(v.begin(), v.end());
//	//再把数据拷贝回去
//	size_t i = 0;
//	for (auto e : lt1)
//	{
//		e = v[i];
//	}
//	int end1 = clock();
//
//	int begin2 = clock();
//	lt.sort();
//	int end2 = clock();
//
//	printf("vector:%d\n", end1 - begin1);
//	printf("list:%d\n", end2 - begin2);
//
//
//	return 0;
//}

int main()
{
	Mycode::test_list4();
	return 0;
}