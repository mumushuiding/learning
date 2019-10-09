#include<iostream>
#include<string.h>
using namespace std;

class Person{
  char* pName;
public:
  Person(char* pN="noName") {
    cout<<"Constructing "<<pN<<endl;
    pName=new char[strlen(pN)+1];
    if(pName) strcpy(pName,pN);
  }
  ~Person(){ // 析构函数专门做对象销毁时的善后工作
    cout<<"Destructing "<<pName<<endl;
    delete[] pName;
  }
};
int main(){
  Person p1("Randy");
}