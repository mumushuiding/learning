#include<iostream>
#include<vector>
using namespace std;

class Student{
public:
  virtual void calc(){
    cout<<"student tuition"<<endl;
  }
};
class Graduate:public Student{
public:
  void calc(){cout<<"graduate tuition"<<endl;}
};

void fn(Student& x){x.calc();} // x必须为基类的引用性形参，否则不会有多态

int main(){
  Student s;
  Graduate gs;
  vector<Student*> v;
  v.push_back(&s);
  v.push_back(&gs);
  
  for(int i=0;i<v.size();i++){
    fn(*v[i]);
  }
}