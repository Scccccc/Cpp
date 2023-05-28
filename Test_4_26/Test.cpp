#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

void Test1()
{
	Date d1(2023, 5, 28);
	Date d2(2023, 4, 29);
	/*d1.print();
	d2.print();*/

	//cout << (d1 == d2) << endl;

	//d1 += 10000;
	//d1.print();

	//拷贝构造
	Date d3 = d1;
	d3.print();
	//赋值运算符
	d3 = d2;
	d3.print();
	Date d4 = d3 + 50;
	d4.print();



}
int main()
{
	Test1();
	return 0;
}