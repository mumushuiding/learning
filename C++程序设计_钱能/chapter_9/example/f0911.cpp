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
  Person(const Person& s){
    cout<<"copy Constructing "<<s.pName<<endl;
    pName=new char[strlen(s.pName)+1];
    if(pName) strcpy(pName,s.pName);
  }
  void print(){
    cout<<"print: "<<pName<<endl;
  }
  ~Person(){ // 析构函数专门做对象销毁时的善后工作
    cout<<"Destructing "<<pName<<endl;
    delete[] pName;
  }
};
int main(){
  Person p1("Randy");
  p1.print();
  // Person p2(p1);
  Person p2=p1;
  p2.print();
}