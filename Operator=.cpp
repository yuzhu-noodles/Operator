#include<iostream>
using namespace std;

//赋值运算符重载

class Person{
  public:
    Person(int age){
      m_Age = new int(age);
    }
    ~Person(){
      if(m_Age != NULL){
        delete m_Age;
        m_Age = NULL;
      }
    }
     
    //重载赋值运算符
    Person& operator=(Person&p){
      //m_Age = p.m_Age; 编译器提供的浅拷贝

      //应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
      if(m_Age != NULL){
        delete m_Age;
        m_Age = NULL;
      }
      //在堆区开辟空间进行深拷贝
      m_Age = new int(*p.m_Age);
      return *this;   //返回引用是为了进行链式编程 A=B=C
    }
  public:
    int *m_Age;
};

void test01(){
  Person p1(100);
  Person p2(200);
  Person p3(300);
  p3 = p2 = p1;
  cout<<"p1年龄："<<*p1.m_Age<<endl;;
  cout<<"p2年龄："<<*p2.m_Age<<endl;;
  cout<<"p3年龄："<<*p3.m_Age<<endl;;
}
int main()
{
  //如果不提供赋值重载，P1 = p2，p2和p1的m_Age都指向同一块地址，在析构时会重复释放
  //因此需要赋值重载提供深拷贝操作
  test01();
  return 0;
}
