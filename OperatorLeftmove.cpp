#include<iostream>
using namespace std;

//左移运算符重载
class Person{
	//一般不适使用成员函数重载<<运算符，因为无法实现cout在左侧
	public:
		int m_Age;
};

//只能用全局函数重载左移

//本质 operator<< (cout,p) 简化 cout<<p
ostream& operator<<(ostream &cout,Person& p){             //cout  ostream标准输出流，全局只能右一个，因此只能引用
    cout<<"m_Age = "<<p.m_Age;
}
int main(){
	Person A;
	A.m_Age = 10;
	cout<<A<<endl;
	return 0;
}
