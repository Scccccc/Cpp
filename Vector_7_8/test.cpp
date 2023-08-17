#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//迭代器遍历
	vector<int>::iterator it = v1.begin();
	while (it < v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//下标遍历
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//范围for遍历
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector2()
{
	vector<string> vstr;

	string name1("hello");
	vstr.push_back(name1);

	vstr.push_back(string("world"));

	vstr.push_back("hello world");

	for (auto c : vstr)
	{
		cout << c << endl;
	}
	cout << endl;

	vector<int> v1(10, 1);
	for (auto c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	vector<string> v2(10, "fuck");
	for (auto c : v2)
	{
		cout << c << " ";
	}
	cout << endl;

	vector<int> v3(v1.begin(), v1.end());
	for (auto c : v3)
	{
		cout << c << " ";
	}
	cout << endl;

	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto c : v4)
	{
		cout << c << " ";
	}
	cout << endl;

	int arr[] = { 3, 21, 7, 77 };
	vector<int> v5(arr, arr+4);
	for (auto c : v5)
	{
		cout << c << " ";
	}
	cout << endl;

	greater<int> gt;//降序
	sort(v5.begin(), v5.end(), gt);
	for (auto c : v5)
	{
		cout << c << " ";
	}
	cout << endl;

	sort(v5.begin(), v5.end(), greater<int>());
	for (auto c : v5)
	{
		cout << c << " ";
	}
	cout << endl;

	string str1("IM WILLIAM");
	sort(str1.begin(), str1.end());
	for (auto c : str1)
	{
		cout << c << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v1;
	v1.resize(10);

	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2;
	v2.reserve(10);
	cout << v2.capacity() << endl;
	for (size_t i = 0; i < v2.capacity(); i++)
	{
		v2.push_back(i);
	}
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector4()
{
	int arr[] = { 23, 1, 67, 6, 6, 6, 6, 7, 8 };

	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//头插
	v1.insert(v1.begin(), 0);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//头删
	v1.erase(v1.begin());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//指定删除6
	//vector<int>::iterator pos = find(v1.begin(), v1.end(), 6);
	//if (pos != v1.end())
	//{
	//	v1.erase(pos);
	//}
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	// 
	// 
	//指定删除多个6
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 6);
	while (pos != v1.end())
	{
		v1.erase(pos);
		pos = find(v1.begin(), v1.end(), 6);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//assign清楚之前的数据，重新插入
	v1.assign(10, 1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}


int main()
{
	test_vector4();
	return 0;
}