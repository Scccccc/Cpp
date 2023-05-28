#pragma once

#include <iostream>
using namespace std;


class Date
{
public:
	Date(int year = 2000, int month = 11, int day = 28);
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator<(Date& x);
	bool operator==(Date& x);
	bool operator<=(Date& x);

	bool operator>(Date& x);
	bool operator>=(Date& x);
	bool operator!=(Date& x);

	int GetMonthDay(int year, int month);
	Date& operator+=(int day);
	Date operator+(int day);





//private:
	int _year;
	int _month;
	int _day;
};