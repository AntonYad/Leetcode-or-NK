#include<iostream>
using namespace std;
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//class A{};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { cout << "A "<< endl; return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { cout << "B " << endl; return new B; }
//};//void get(Person&  a)//{//	a.f();//}//int main()//{//	Person ps;
//	Student st;
//	get(ps);
//	get(st);//	return 0;//}//void Func(Person& p)
//{
//	f();
//}
//int main()
//	{
//		Person ps;
//		Student st;
//
//		Func(ps);
//		Func(st);
//		return 0;
//	}
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
/*c*//*lass Car{
public:
	virtual void Drive(){ cout << "Car" << endl; }
};
class Benz :public Car {
public:
	void Drive() override { cout << "Car" << endl; }
};
void get(Car& a)
{
	a.Drive();
}
int main()
{
	Car a;
	Benz b;
	get(a);
	get(b);
	return 0;
}*/
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//int main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
// 这里常考一道笔试题：sizeof(Base)是多少？

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};//int main()//{//	Base a;//	return 0;//}//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//	//char _ch = 10;
//};
//
//Base b;
//int main()
//{
//	cout << sizeof(Base) << endl;
//
//	// b1和b2的虚表是不是一个？
//	// 虚表存在哪的？
//	// 虚表是在什么阶段生成的？-》编译时
//	Base b1;
//	Base b2;
//
//	printf("虚表指针：%p\n", *((int*)&b1));
//	int a = 0;
//	static int b = 0;
//	int* p = new int;
//	char* str = "hello world";
//	printf("栈：%p\n", &a);
//	printf("数据段(静态区)：%p\n", &b);
//	printf("堆：%p\n", p);
//	printf("代码段(常量区)：%p\n", str);
//
//	return 0;
//}
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int b = 1;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int d = 2;
};

typedef void(*VFUNC)();

void PrintVFT(VFUNC* vftable)
{
	printf("虚表指针：%p\n", vftable);
	for (int i = 0; vftable[i] != nullptr; ++i)
	{
		printf("vftale[%d]:%p->", i, vftable[i]);
		VFUNC f = vftable[i];
		f();
		//(*f)();
	}
}

int main()
{
	Base b;
	Derive d;

	PrintVFT((VFUNC*)(*((int*)&d)));
	cout << endl << endl;

	PrintVFT((VFUNC*)(*((int*)&b)));


	return 0;
}