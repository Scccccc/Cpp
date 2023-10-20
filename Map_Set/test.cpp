#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

#include "Map.h"
#include "Set.h"
//
void func(Mycode::map<int, int> m)
{
	//Mycode::map<int, int>::const_iterator it = m.begin();
	//auto it = m.begin();
	//while (it != m.end())
	//{
	//	//it->second = 20;
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;
	for (const auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}

int main()
{
	Mycode::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(5, 6));
	m.insert(make_pair(6, 6));
	m.insert(make_pair(7, 7));

	for (const auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	Mycode::map<string, string> dict;
	dict["left"];
	dict["right"];
	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	dict["left"] = "左";
	dict["right"] = "右";
	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;




	//Mycode::map<int, int>::const_iterator it = m.begin();
	//while (it != m.end())
	//{
	//	//it->first = 10;
	//	//it->second = 20;
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;

	//for (const auto& e : m)
	//{
	//	//e.first = 10;
	//	//e.second = 20;
	//	cout << e.first << ":" << e.second << endl;
	//}
	//cout << endl;

	Mycode::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	s.insert(20);
	s.insert(22);
	s.insert(32);
	Mycode::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << endl;
		++sit;
	}

	//func(m);
	
	return 0;
}