#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

////虚函数的析构
//class Person
//{
//public:
//	virtual ~Person()
//	//~Person()
//
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	//~Student()
//	{
//		cout << "~Student()" << endl;
//		delete[] ptr;
//	}
//protected:
//	int* ptr = new int[10];
//};
//int main()
//{
//	//Person p;
//	//Student s;
//	Person* p = new Person;
//	delete p;
//
//	/*p = new Student;
//	delete p;*/
//	return 0;
//}


//class Person
//{
//public:
//	virtual Person* Buytickets() const
//	{
//		cout << "Person-全价" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual Student* Buytickets() const
//	{
//		cout << "Student-半价" << endl;
//		return 0;
//	}
//};
//
//void func(const Person* p)
//{
//	
//	p->Buytickets();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	func(&p);
//	return 0;
//}

//override检查子类虚函数是否构成重写
class Car
{
public:
	virtual void Drive() const
	{}
};

class Audi : public Car
{
	virtual void Drive() const override
	{
		cout << "Audi" << endl;
	}
};

void func(const Car& c)
{
	c.Drive();
}

int main()
{
	Car c;
	
	func(Audi());
	return 0;
}