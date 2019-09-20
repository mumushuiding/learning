#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
  for(int i=1;i<=7;i++){
    // 空格变化为 y=|x-4|
    // * 变化为 y=2*(-|x-4|+4)-1
    cout<<setfill(' ')<<setw(abs(i-4))<<""
      <<setfill('*')<<setw(2*(-abs(i-4)+4)-1)<<""<<endl;
  }
}