#include<iostream>
#include<exception>
using namespace std;
class MyException:public exception{
public:
  virtual const char* what() const throw(){
    return "some err";
  }
};
int main(){
  try{
    throw MyException();
  } catch(exception& e){
    cout<<typeid(e).name()<<endl;
    cout<<e.what()<<endl;
  }
  cout<<"The End"<<endl;
}