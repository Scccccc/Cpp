#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

#include "BinarySearchTree.h"

//class A 
//{ 
//public: 
//	void test(float a) 
//	{ 
//		cout << a; 
//	} 
//}; 
//class B :public A 
//{ 
//public: 
//	void test(int b) 
//	{ 
//		cout << b; 
//	} 
//}; 
//void main() 
//{ 
//	A* a = new A; 
//	B* b = new B; 
//	a = b; 
//	a->test(1.1); 
//}

//int main()
//{
//	testBSTree();
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int c = 1;
//	b = c;
//	b++;
//	cout << a << endl;
//	return 0;
//}

//class A
//{
//public:
//    A()
//        :m_iVal(0)
//    { 
//        test(); 
//    }
//    virtual void func()
//    { 
//        std::cout << m_iVal << " ";
//    }
//    void test()
//    { 
//        func(); 
//    }
//public:
//  int m_iVal;
//};
//
//class B : public A
//{
//public:
//    B() 
//    { 
//        test(); 
//    }
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << " ";
//    }
//
//};
//int main()
//{
//    A* p = new B;
//    p->test();
//
//    return 0;
//}

//class A
//{
//public:
//	A()
//	{}
//	virtual void func()
//	{}
//
//};
//
//class B : public A
//{
//public:
//	B()
//	{}
//
//};
//
//int main()
//{
//	B b;
//	A a;
//	A* p = &b;
//	return 0;
//}

//class A
//{
//public:
//    virtual void f()
//    {
//        cout << "A::f()" << endl;
//    }
//};
//
//class B : public A
//{
//private:
//    virtual void f()
//    {
//        cout << "B::f()" << endl;
//    }
//};
//
//int main()
//{
//    A* pa = new B;
//
//    pa->f();
//    return 0;
//}

int main()
{
	key_value::testBSTree2();
	return 0;
}