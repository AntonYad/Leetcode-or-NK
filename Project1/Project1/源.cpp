#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//private:
//	string _name = "peter"; // ����
//protected:
//	int _age = 18;  // ����
//};
//
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//public:
//	void func()
//	{
//		//cout << _name << endl; // ���ɼ�
//		cout << _age << endl;  // protected
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	//s._name;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}
class A
{
public:
	int _a;
};

// class B : public A
class B : virtual public A
{
public:
	int _b;
};

// class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

// ����ģ��  -- �������ڴ�����δ洢��ģ��
// ������̽��C++����ģ�͡� ���Ƽ�����
// ��STLԴ��������  �Ƽ���
// ��effctive C++�� �Ƽ���
int main()
{
	D d;
	cout << sizeof(d) << endl;

	d._a = 0;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}