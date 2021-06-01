#include<iostream>
using namespace std;

//加号运算符重载

class Person{
	public:
		Person() {}
		Person(int age){
			m_Age = age;
		}
		//成员函数重载+
/*  	Person operator+(const Person& p){
			Person temp;   //这块必须自己设置默认构造函数，不然会出错
			temp.m_Age = this->m_Age + p.m_Age;
			return temp;
		}
		*/
		//重载-
		Person operator-(const Person& p){
			Person temp;
			temp.m_Age = this->m_Age - p.m_Age;
			return temp;
		}
		//重载*
        Person operator*(const Person& p){
			Person temp;
			temp.m_Age = this->m_Age * p.m_Age;
			return temp;
		}
		//重载/
        Person operator*(const Person& p){
			Person temp;
			temp.m_Age = this->m_Age / p.m_Age;
			return temp;
		//重载%
        Person operator*(const Person& p){
			Person temp;
			temp.m_Age = this->m_Age / p.m_Age;
			return temp;
	public:

	public:
		int m_Age;
};

//全局函数重载+
Person operator+(const Person& p1,const Person& p2){
	Person temp;
	temp.m_Age = p1.m_Age + p2.m_Age;
	return temp;
}

//本质：
//Person p3 = p1.operator+(p2) //成员函数
//Person p3 = operator+(p1,p2)  //全局函数

//运算重载符也可以发生 函数重载
Person operator+(const Person& p,int n){
	Person temp;
	temp.m_Age = p.m_Age + n;
	return temp;
}
void test01(){  //测试operator+
	Person p1(10);
	Person p2(20);
	Person p3 = p1 + p2;
	cout<<"p3的年龄："<<p3.m_Age<<endl;
	Person p4 = p1 + 100;
	cout<<"p4的年龄："<<p4.m_Age<<endl;
}
void test02(){  //测试operator-
	Person p1(20);
	Person p2(10);
	Person p3 = p1 - p2;
	cout<<"p3的年龄："<<p3.m_Age<<endl;
}
void test03(){  //测试operator*
    Person p1(10);
	Person p2(10);
	Person p3 = p1 * p2;
	cout<<"p3的年龄："<<p3.m_Age<<endl;
}
int main(){
	test03();
	return 0;
}
