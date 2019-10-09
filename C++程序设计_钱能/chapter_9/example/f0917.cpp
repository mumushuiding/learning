#include<iostream>
#include<string.h>
using namespace std;

class Person{
  char* pName;
public:
  Person(char* pN="noName"){ // 构造函数
    cout<<"Constructing "<<pN<<endl;
    pName=new char[strlen(pN)+1];
    if(pName) strcpy(pName,pN);
  }
  Person& operator=(Person& s){ // 重载操作符“=”的定义
    cout<<"Assigning "<<s.pName<<endl;
    if (this==&s) return s;
    delete[] pName;  // 先将原来对象的资源释放掉
    pName=new char[strlen(s.pName)+1];
    if(pName) strcpy(pName,s.pName);
    return *this;

  }
  ~Person(){ // 析构函数
    cout<<"Destructing "<<pName<<endl;
    delete[] pName;
  }
};

int main(){
  Person p1("Tom");
  Person p2("Lily");
  p2=p1;
}