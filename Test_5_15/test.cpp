#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


class A
{
public:
	A(int a = 0, int b = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	A(const A& aa)
		: _a(aa._a)
	{
		cout << "A(const A& aa)" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1, 1);
//	free(p1);
//	delete p2;
//
//	A* p3 = (A*)malloc(sizeof(A) * 10);
//	A* p4 = new A[4]{ A(1,1), A(2,2),A(3,3),A(4,4) };
//	free(p3);
//	delete[] p4;
//
//	return 0;
//}

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	//replacement new 显示调用构造函数
//	new(p1)A;
//	p1->~A();
//
//	free(p1);
//
//	return 0;
//}

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	//显示调用构造函数
//	new(p1)A(1,2);
//	//显示调用析构函数
//	p1->~A();
//
//	free(p1);
//	return 0;
//}

template <typename Tp>
void Swap(Tp& x, Tp& y)
{
	Tp tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 0, b = 1;
	double c = 1.1, d = 2.2;
	Swap(a, b);
	Swap(c, d);

	return 0;
}