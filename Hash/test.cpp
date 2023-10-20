#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "HashTable.h"

//int main()
//{
//	int arr[] = { 10, 20, 7, 15, 25, 44, 4, 10 };
//	Open_address::HashTable<int, int> ht;
//	for (auto& e : arr)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//	cout << endl;
//
//	Open_address::HashTable<string, string> dict;
//	dict.Insert(make_pair("left", "右边"));
//	dict.Insert(make_pair("insert", "插入"));
//
//	auto ret = dict.Find("left");
//	ret->_kv.second = "xxx";
//
//	Open_address::DefultHashfunc<string> s;
//	cout << s.operator()("abcd") << endl;
//	cout << s.operator()("bacd") << endl;
//	cout << s.operator()("edbc") << endl;
//
//
//	Open_address::DefultHashfunc<int> i;
//	cout << i.operator()(-10) << endl;
//	cout << i.operator()(20) << endl;
//	cout << i.operator()(30) << endl;
//
//
//	return 0;
//}

//int main()
//{
	//int arr[] = { 10, 20, 7, 15, 25, 44, 4, 10 };
	//hash_bucket::HashTable<int, int> ht;
	//for (auto& e : arr)
	//{
	//	ht.Insert(make_pair(e, e));
	//}
	//cout << endl;

	//ht.Print();

	//ht.Erase(10);
	//ht.Erase(20);
	//ht.Erase(4);
	//ht.Erase(44);
	//ht.Erase(15);
	//ht.Erase(25);
	//ht.Print();

	//hash_bucket::HashTable<string, string> dict;
	//dict.Insert(make_pair("left", "右边"));
	//dict.Insert(make_pair("insert", "插入"));

	//dict.Print();
	//auto ret = dict.Find("left");
	//ret->_kv.second = "xxx";

	//hash_bucket::DefultHashfunc<string> s;
	//cout << s.operator()("abcd") << endl;
	//cout << s.operator()("bacd") << endl;
	//cout << s.operator()("edbc") << endl;


	//hash_bucket::DefultHashfunc<int> i;
	//cout << i.operator()(-10) << endl;
	//cout << i.operator()(20) << endl;
	//cout << i.operator()(30) << endl;

	//return 0;
//}

#include "UnorderedMap.h"
#include "UnorderedSet.h"

int main()
{
	Mycode::unordered_set<int> s;

	s.insert(10);
	s.insert(3);
	s.insert(2);
	s.insert(5);
	s.insert(6);
	s.insert(6);
	s.insert(6);

	s.Erase(6);

	Mycode::unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 10;
		cout << *it << endl;
		++it;
	}


	Mycode::unordered_map<string, string> m;

	m.insert(make_pair("left", "左边"));
	m.insert(make_pair("insert", "插入"));
	m.insert(make_pair("loop", "循环"));

	auto mit = m.Erase("loop");

	for (auto& str : m)
	{
		str.second += 'x';
		cout << str.first << ":" << str.second << endl;
	}

	return 0;
}