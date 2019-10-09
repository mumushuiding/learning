#include<iostream>
using namespace std;

class StudentID{
public:
  int value;
  StudentID(){
    static int nextStudentID=0;
    value=++nextStudentID;
    cout<<"Assigning student id "<<value<<"\n";
  }
};
class Student{
  string name;
  StudentID id;
public:
  Student(string n="noName"){
    cout<<"Constructing student " +n+ " \n";
    name=n;
  }
};

int main(){
  Student s("Lilei");
  Student s1("Tom");
  StudentID id2;
  cout<<id2.value<<endl;
}