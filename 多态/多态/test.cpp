#include<iostream>
using namespace std;
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//int main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�

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
//	// b1��b2������ǲ���һ����
//	// �������ĵģ�
//	// �������ʲô�׶����ɵģ�-������ʱ
//	Base b1;
//	Base b2;
//
//	printf("���ָ�룺%p\n", *((int*)&b1));
//	int a = 0;
//	static int b = 0;
//	int* p = new int;
//	char* str = "hello world";
//	printf("ջ��%p\n", &a);
//	printf("���ݶ�(��̬��)��%p\n", &b);
//	printf("�ѣ�%p\n", p);
//	printf("�����(������)��%p\n", str);
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
	printf("���ָ�룺%p\n", vftable);
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