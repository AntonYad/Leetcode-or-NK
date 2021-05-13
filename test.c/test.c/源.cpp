#include<iostream>
using namespace std;
//int fun()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; j++, i++)
//	{
//		k++;
//	}
//	return k;
//}
//int main()
//{
////int a[] = { 1, 2, 3, 4 };
////int *b = a;
////*b += 2;
////*(b + 2) = 2;
////b++;
////printf("%d %d", *b, *(b + 2));
//	/*char a[10] = { '1', '2', '3', '4' }, *p; int i;
//	i = 1;
//	p = a + i;
//	printf("%s\n", p - 1);*/
//	/*int n[][3] = { 10, 20, 30, 40, 50, 60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << *(p[0] + 1) << (*p)[2] << endl;*/
//
//}

//char fun(char x, char y)
//{
//	if (x < y)
//	{
//		return x;
//	}
//	return y;
//}
//int main()
//{
//	/*i*//*nt a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));*/
//	/*int m = 0123, n= 100;
//	printf("%o \n", n);
//	return 0;*/
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr = (int*)(&a +1);
//	printf("%d", *(ptr - 1));
//}
//class A{
//public:
//	A() :m_iVal(0)
//	{
//		test();
//	}
//	virtual void func(){
//		std::cout << m_iVal << endl;
//	}
//	void test()
//	{
//		func();
//	}
//public:
//	int m_iVal;
//};
//class B : public A
//{
//public:
//	B()
//	{
//		test();
//	}
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << endl;
//	}
//};
//int main()
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}
//class A{ int i; };
//class B
//{
//	A *p;
//public:
//	B(){ p = new A; }
//	~B(){ delete p; }
//};
//void sayHello(B b)
//{}
//int main()
//{
//	B b;
//	sayHello(b);
//}
//class Myclass
//{
//public:
//	Myclass(int i = 0){ cout << 1; }
//	Myclass(const Myclass&x){ cout << 2; }
//	Myclass& operator=(const Myclass&x){ cout << 3; return *this; }
//	~Myclass(){ cout << 4; }
//};
//int main()
//{
//	Myclass obj1(1), obj2(2), obj3(obj1);
//	return 0;
//}
int main()
{
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	p1++;
	p = reinterpret_cast<char*>(p1);
	cout << p << endl;
	return 0;
}