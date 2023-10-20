#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "string.h"

void string_test1()
{
	Mycode::string s1("hello world");
	cout << s1.c_str() << endl;

	Mycode::string s2;
	cout << s2.c_str() << endl;

	cout << s1.size() << endl;

	Mycode::string s3("Hello World");
	s3[0]++;
	cout << s3.c_str() << endl;

	Mycode::string::iterator it = s1.begin();
	while(it != s1.end())
	{
		*it += 1;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	Mycode::string::const_iterator rit = s3.begin();
	while (rit != s3.end())
	{
		/**rit += 1;*/
		cout << *rit << " ";
		rit++;
	}

	cout << endl;

	Mycode::string s4("Im William");
	for (auto ch : s4)
	{
		cout << ch << " ";
	}
}

void string_test2()
{
	Mycode::string s1("hello world");
	//cout << s1.size() << endl;

	//s1.reserve(30);

	//s1.push_back('x');
	//cout << s1.c_str() << endl;

	s1.append("###");
	cout << s1.c_str() << endl;

	s1 += 'K';
	cout << s1.c_str() << endl;

	s1 += "HHHHhhhhhhhhhhhhhhhhhhhhh";
	cout << s1.c_str() << endl;

	Mycode::string s2("hello world");
	s2.insert(0, "####");
	cout << s2.c_str() << endl;

	Mycode::string s3("hellow orld");
	s3.insert(8, 7, 'x');
	cout << s3.c_str() << endl;

	s3.erase(8, 7);
	cout << s3.c_str() << endl;
	cout << s3.size() << endl;


}

void string_test3()
{
	Mycode::string s1("hellow orld");
	s1.erase(3, 20);
	cout << s1.c_str() << endl;

	s1.erase(0, 2);
	cout << s1.c_str() << endl;

	Mycode::string s2("hellow orld");
	cout << s2.find('d', 5) << endl;

}

void string_test4()
{
	//Mycode::string str = "HEllo world";
	//Mycode::string str2 = str.substr(1, 2);
	//cout << str2.c_str() << endl;

	Mycode::string s1 = "Hello world";
	s1.resize(8);
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;

	Mycode::string s2 = "Hello world";
	s2.resize(13, 'x');
	cout << s2.c_str() << endl;
	cout << s2.size() << endl;

	Mycode::string s3 = "Hello world";
	s3.resize(15, 'y');
	cout << s3.c_str() << endl;
	cout << s3.size() << endl;

}

void string_test5()
{
	Mycode::string s1 = "hello world";
	cout << s1 << endl;
	Mycode::string s2;
	cin >> s2;
	cout << s2 << endl;

	cin >> s2;
	cout << s2 << endl;

}


void string_test6()
{
	Mycode::string s1("hello");
	Mycode::string s2("hello");
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 == s2) << endl << endl;

	Mycode::string s3("hello");
	Mycode::string s4("helloxxxx");
	cout << (s3 < s4) << endl;
	cout << (s3 > s4) << endl;
	cout << (s3 == s4) << endl << endl;

	Mycode::string s5("helloxxxx");
	Mycode::string s6("hello");
	cout << (s5 < s6) << endl;
	cout << (s5 > s6) << endl;
	cout << (s5 == s6) << endl << endl;

}

void string_test7()
{
	Mycode::string s1("hello");
	Mycode::string s2(s1);
	cout << s1 << endl;
	cout << s2 << endl;

	Mycode::string s3;
	Mycode::string s4("life is sucks");
	s3 = s4;
	cout << s3 << endl;
	cout << s4 << endl;

}

void string_test8()
{
	Mycode::string s1("hello");
	s1 += '\0';
	s1 += "xxxxxxxxx";
	cout << s1 << endl;

}


int main()
{
	string_test8();
	return 0;
}