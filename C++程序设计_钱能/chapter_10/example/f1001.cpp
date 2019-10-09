#include<iostream>
using namespace std;

class BaseClass{
protected:
 int a;
public:
  int b;
};
class B:public BaseClass{
  int c;
public:
  void print(){
    cout<<a<<endl;
  }
};
int main(){

}