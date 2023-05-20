#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//int main()
//{
//	int a = 1;
//	int& b = a;
//	cout << &a << endl << &b << endl;
//	return 0;
//}


//int main()
//{
//	int a = 1;
//	int& b = a;
//	int c = 10;
//	b = c;
//	cout << a << endl << b << endl;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& ra; // 该条语句编译时会出错
//}

////平常写的交换两个数，使用指针，还要解引用
//void Swap(int* left, int *right)
//{
//	int tmp = *left;
//	*left = *right;
//	*right = tmp;
//}


//int& Count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int n = Count();
//	printf("%d\n", n);
//}


//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
// 
// #include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}


//int main()
//{
//	//不同类型会产生临时变量（临时变量具有常性）
//	double a = 1.11;
//	int i = a;
//
//
//	int& ii = a;//
//
//	const int& rii = a;//可以
//	return 0;
//}

//int main()
//{
//	int a = 0;
//
//	auto b = 11;//根据右边的类型，自动推到
//	return 0;
//}

//#include<map>
//#include<string>
//#include<vector>
//
//int main()
//{
//	int a = 0;
//	int b = a;
//	auto c = a; // 根据右边的表达式自动推导c的类型
//	auto d = 1 + 1.11; // 根据右边的表达式自动推导d的类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	vector<int> v;
//
//	// 类型很长
//	//vector<int>::iterator it = v.begin();
//	// 等价于
//	auto it = v.begin();
//
//	std::map<std::string, std::string> dict;
//	//std::map<std::string, std::string>::iterator dit = dict.begin();
//	// 等价于
//	auto dit = dict.begin();
//
//	return 0;
//}
//
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl;
//}
//
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//		e *= 2;//每次对数组的值*=2
//
//	for (auto e : array)
//		cout << e << " ";//打印
//}

//#define Add(x, y)  ((x)+(y))

//inline int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << Add(i, i + 1) << endl;
//	}
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}
