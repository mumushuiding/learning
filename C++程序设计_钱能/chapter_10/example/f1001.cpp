#include<iostream>
using namespace std;

class BaseClass{
protected:
 int a;
public:
  int b;
  // BaseClass(int a=2,int b=3):a(a),b(b){
  //   cout<<"construct"<<endl;
  // }
  BaseClass(int a):a(a){
    cout<<"construct"<<endl;
  }
};
class B:public BaseClass{
  int c;
public:
  B(int c=3):BaseClass(4){
    ;
  }
  void print(){
    cout<<a<<endl;
  }
};
int main(){
  B b;
  b.print();
}