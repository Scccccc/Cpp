#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Stack
//{
//public:
//	Stack(int capcity = 4)
//	{
//		cout << "Stack(int capcity = 4)" << endl;
//		_a = (int*)malloc(sizeof(int) * capcity);
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capcity = capcity;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capcity;
//};
//
//int main()
//{
//	Stack st(10);
//
//	return 0;
//}


class Stack
{
public:
	Stack(int capcity = 4)
	{
		cout << "Stack()" << endl;
		_a = (int*)malloc(sizeof(int) * capcity);
		if (_a == NULL)
		{
			perror("malloc fail");
			return;
		}
		_top = 0;
		_capcity = capcity;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_top = _capcity = 0;
	}

private:
	int* _a = nullptr;
	int _top = 0;
	int _capcity;
};


class MyQueue
{
private:
	Stack pushst;
	Stack pophst;
};

//int main()
//{
//	Stack st;
//	Stack st2(10);
//
//	MyQueue q;
//
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date(const Date& d)
//	//{
//	//	cout << "Date(Date d)" << endl;
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	//可以不写拷贝构造，会自动生成拷贝构造
//	Date d1(2023, 4, 25);
//	Date d2(d1);
//	return 0;
//}

class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

//private:
	int _year;
	int _month;
	int _day;
};

//operator 内置类型比较大小函数

bool operator<(const Date& x1, const Date& x2)
{
	if (x1._year < x2._year)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month < x2._month)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
	{
		return true;
	}

	return false;
}
bool operator>(const Date& x1, const Date& x2)
{
	if (x1._year > x2._year)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month > x2._month)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
	{
		return true;
	}

	return false;
}

int main()
{
	Date d1(2023, 4, 25);
	Date d2(2023, 5, 26);

	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;

	return 0;
}