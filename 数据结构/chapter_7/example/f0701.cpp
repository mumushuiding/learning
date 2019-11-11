#include<iostream>
using namespace std;
int main(){
  for(int i=17;i<=32;i++){
    std::cout<<"size 1="<<((i+15)>>4)<<std::endl;
  }
}