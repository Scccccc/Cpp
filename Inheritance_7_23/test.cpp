#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;


class A
{
//protected:
public:
	int _a;
};

class B : virtual public A
{
//protected:
public:
	int _b;
};

class C : virtual public A
{
//protected:
public:
	int _c;
};
class D : public B, public C 
{
//protected:
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 18;
	d.C::_a = 30;
	d._b = 3;
	d._c = 4;
	d._d = 5;


	return 0;
}
