#include<iostream>
using namespace std;

//重载递增/递减运算符

class MyInt{
    friend ostream& operator<<(ostream& cout,MyInt M);
	public:
		MyInt(){
			m_Num = 0;
		}
    MyInt(int num){
      m_Num = num;
    }
		//前置++重载
	    MyInt& operator++(){  //注意要返回引用，是为了一直对一个数据进行操作
		    m_Num++;
		    return *this;
	    }
		//后置++重载
		MyInt operator++(int){  //加占位参数，实现函数重载，返回值不可以用来区分函数重载
			MyInt temp = *this;  //记录原结果
			m_Num++;
			return temp; //返回记录结果
		}
		//后置++要返回值，是因为temp是局部变量
   
    //前置--重载
    MyInt& operator--(){
      m_Num--;
      return *this;
    }
    //后置--重载
    MyInt operator--(int){
      MyInt temp = *this;
      m_Num--;
      return temp;
    }
	 private:
		int m_Num;
};
//左移运算符重载
ostream& operator<<(ostream& cout,MyInt M){
	cout<< M.m_Num;
	return cout;
}
void test01(){
	MyInt m;
	cout<<"前置++"<<endl;
  cout<< m <<endl;
	cout<< ++m <<endl;
	cout<<"后置++"<<endl;
  MyInt mm;
	cout<< m++ <<endl;  
	cout<< m <<endl;
}

void test02(){
  MyInt M;
  cout<<"前置--"<<endl;
  cout<< M <<endl;
  cout<< --M <<endl;
  cout<<"后置--"<<endl;
  cout<< M-- <<endl;
  cout<< M <<endl;
}
int main()
{
  test02();
  return 0;
}
