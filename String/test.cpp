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


}

int main()
{
	string_test2();
	return 0;
}