#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <functional>

using namespace std;

#include "SmartPtr.h"
//int main()
//{
//	Mycode::shared_ptr<int> p1(new int(1));
//	Mycode::shared_ptr<int> p2(new int(2));
//	Mycode::shared_ptr<int> p3(p1);
//	Mycode::shared_ptr<int> p4(p3);
//
//	p2 = p4;
//
//	//Mycode::auto_ptr<int> p1(new int(1));
//	//Mycode::auto_ptr<int> p2(new int(1));
//	////悬空
//	//Mycode::auto_ptr<int> p3(p1);
//	//++(*p1);
//
//	//Mycode::unique_ptr<int> p1(new int(1));
//	//Mycode::unique_ptr<int> p2(new int(2));
//	//Mycode::unique_ptr<int> p3(p1);
//
//	//p1 = p2;
//
//	return 0;
//}
//template<class T>
//struct Node
//{
//	int _val;
//	////循环引用
//	//Mycode::shared_ptr<Node> _next;
//	//Mycode::shared_ptr<Node> _prev;
//	Mycode::weak_ptr<Node> _next;
//	Mycode::weak_ptr<Node> _prev;
//
//};
//
//int main()
//{
//	Mycode::shared_ptr<Node> p1(new Node);
//	Mycode::shared_ptr<Node> p2(new Node);
//
//	p1->_next = p2;
//	p2->_prev = p1;
//
//	return 0;
//}
//
//int main()
//{
//	char* ptr = new char[1024 * 1024 * 1024];
//	return 0;
//}

template<class T>
struct DestroyArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

int main()
{
	//定制删除器
	Mycode::shared_ptr<int> p1(new int[10], DestroyArray<int>());
	Mycode::shared_ptr<FILE> p2(fopen("test.txt", "r"), [](FILE* ptr) {fclose(ptr); });
	Mycode::shared_ptr<double> p3((double*)malloc(sizeof(double)), [](double* ptr) {free(ptr); });

	return 0;
}