#include<iostream>
using namespace std;
#include<string.h>

//关系运算符重载

class Person{
  public:
    Person(int age,string name){
      m_Age = age;
      m_Name = name;
    }
    //==重载
    bool operator==(Person& p){
      if(m_Age == p.m_Age && m_Name == p.m_Name)
        return true;
      else 
        return false;
    }
    //!= 与==返回值相反
  private:
    int m_Age;
    string m_Name;
};

void test(){
  Person p1(10,"haha");
  Person p2(20,"hehe");
  if(p1 == p2)
    cout<<"p1等于p2"<<endl;
  else 
    cout<<"p1不等于p2"<<endl;
}
int main(){
  test();
  return 0;
}
