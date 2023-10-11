#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
////加上const既可以接受左值也可以接受右值
//void func(const int& a)
//{
//	cout << "void func(int& a)" << endl;
//}
//
////void func(int&& a)
////{
////	cout << "void func(int&& a)" << endl;
////}
//
//int main()
//{
//	int a = 10;
//	int b = 0;
//	//左值
//	func(a);
//	//右值
//	func(a+b);
//	return 0;
//}

//包装器
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};
//int main()
//{
//	// 函数指针
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	function<double(double)> func1 = f;
//	function<double(double)> func2 = Functor();
//	function<double(double)> func3 = [](double d)->double { return d / 4; };
//
//	vector<function<double(double)>> v = { f, Functor(), [](double d)->double { return d / 4; }};
//	double n = 3.5;
//	for (auto f : v)
//	{
//		cout << f(n++) << endl;
//	}
//
//	return 0;
//}

int Sub(int x, int y, int rate)
{
	return (x - y)*rate;
}

int Ssub(int x, int y)
{
	return (x - y);
}

class A
{
public:
	static int sub(int x, int y)
	{
		return x + y;
	}

	int plus(int x, int y)
	{
		return x * y;
	}
};

int main()
{
	function<double(double)> func1 = f;
	cout << useF(func1, 11.11) << endl;

	function<double(double)> func2 = Functor();
	cout << useF(func2, 11.11) << endl;

	function<double(double)> func3 = [](double d) {return d / 4; };
	cout << useF(func3, 11.11) << endl;

	//绑定
	//全局函数
	function<int(int, int)> rSub1 = bind(Ssub, placeholders::_2, placeholders::_1);
	cout << rSub1(10, 5) << endl;
	//固定参数
	function<int(int, int)> rSub2 = bind(Sub, placeholders::_2, placeholders::_1, 3);
	cout << rSub2(10, 5) << endl;
	//静态成员函数
	function<int(int, int)> classA1 = bind(A::sub, placeholders::_1, placeholders::_2);
	cout << classA1(10, 5) << endl;
	//非静态成员函数
	function<int(int, int)> classA2 = bind(&A::plus, A(), placeholders::_1, placeholders::_2);
	cout << classA2(10, 5) << endl;
	return 0;
}