#include<iostream>
using namespace std;

class StudentID{
  int value;
public:
  StudentID(int id=0) { // 参数默认，这样无参函数的调用也能通过
    value=id;
    cout<<"Assgining student id "<<value<<endl;
  }
};
class Student{
  string name;
  StudentID id;
public:
  Student(string n="noName",int ssID=0) {
    cout<<"Constructing student " +n+ "\n";
    name=n;
    StudentID id(ssID);
  }
};

int main(){
  Student s;
  Student s1("Rand",30);
}