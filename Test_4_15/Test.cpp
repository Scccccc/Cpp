#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"


//int a = 0;
//namespace William
//{
//	int a = 1;
//}
//
////展开命名空间
////using namespace William;
//int main()
//{
//	//int a = 2;
//	printf("%d\n", a);
//	//printf("%d", ::a);
//	return 0;
//}

//int a = 0;
//
//namespace William
//{
//	int a = 1;
//}
//
//int main()
//{
//	printf("%d \n", ::rand);
//	printf("%d", William::rand);
//	return 0;
//}
//

//namespace William
//{
//	int rand = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}

//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int a;
//		int b;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d \n", N1::Add(1, 2));
//	printf("%d \n", N1::N2::Sub(3, 2));
//
//	return 0;
//}

//void Func(int a = 0)
//{
//	printf("%d\n", a);
//}
//
//int main()
//{
//	Func(10);
//	return 0;
//}

//int main()
//{
//	struct Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 1.1);
//
//
//	
//	return 0;
//}

void Func(int x)
{
	printf("%d", x);
}

void Func(double c)
{
	printf("%f", c);
}

int main()
{
	Func(1.1);
}