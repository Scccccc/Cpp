#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


class B
{
public:
	B(int a = 0)
		:_a(a)
	{

	}
private:
	int _a;
};

class A
{
public:
	A(int& b, int n)
		:_b(b)
		,_n(n)
	{}
	
private:
	B _abov;
	int& _b;
	const int _n;
};


int main()
{
	int b = 0;
	A aa1(b, 1);


	return 0;
}