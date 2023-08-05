#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	string s1("Hello World!");
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.resize(200);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.at(0) = 'x';
//	cout << s1 << endl;
//
//
//	return 0;
//}

//把空格换成20%
//int main()
//{
//	string s1("hello world!");
//	string s2;
//
//	for (auto e : s1)
//	{
//		if (e != ' ')
//		{
//			s2 += e;
//		}
//		else
//		{
//			s2 += "20%";
//		}
//	}
//	s1 = s2;
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//	return 0;
//}

// 分割网址
//int main()
//{
//	string url = "https://www.youtube.com/watch?v=yPTOVZykwyc";
//
//	size_t pos1 = url.find("://");
//	string protocol;
//	if (pos1 != string::npos)
//	{
//		protocol = url.substr(0, pos1);
//	}
//	cout << protocol << endl;
//
//	size_t pos2 = url.find('/', pos1+3);
//	string domain;
//	string uri;
//	if (pos2 != string::npos)
//	{
//		domain = url.substr(pos1 + 3, pos2-(pos1+3));
//		uri = url.substr(pos2 + 1);
//	}
//
//	cout << domain << endl;
//	cout << uri << endl;
//	return 0;
//}

//字符串最后一个单词的长度
//int main()
//{
//	string str;
//	getline(cin, str);
//	size_t pos = str.rfind(' ');
//	if (pos != string::npos)
//	{
//		cout << str.size() - (pos + 1) << endl;
//	}
//	else
//	{
//		cout << str.size() << endl;
//	}
//}

//
//int main()
//{
//    string str = "1234";
//    int num = stoi(str);
//
//    cout << num << endl;
//}