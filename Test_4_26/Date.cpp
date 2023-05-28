#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}


bool Date::operator<(Date& x)
{
	if (_year < x._year)
	{
		return true;
	}
	else if (_year == x._year && _month < x._month)
	{
		return true;
	}
	else if (_year == x._year && _month == x._month && _day < x._day)
	{
		return true;
	}
	
	return false;
}

bool Date::operator==(Date& x)
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}

bool Date::operator<=(Date& x)
{
	return *this < x || *this == x;
}

bool Date::operator>(Date& x)
{
	return !(*this < x);
}

bool Date::operator>=(Date& x)
{
	return !(*this < x) || *this == x;
}

bool Date::operator!=(Date& x)
{
	return !(*this == x);
}


int Date::GetMonthDay(int year, int month)
{
	int dayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 29;
	}
	else
	{
		return dayArr[month];
	}
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
}