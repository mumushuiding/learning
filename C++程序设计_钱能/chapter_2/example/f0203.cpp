#include<iostream>
using namespace std;
void sphere();
int main(){
  sphere();
}
void sphere(){
  double radius;
  cout<<"Please input radius:";
  cin>>radius;
  cout<<"The result is "<<radius*2*3.14<<"\n";
}