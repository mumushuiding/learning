// =======================
// f0301 打印-1234567的二进制位码
// =======================
#include<iostream>
using namespace std;
int main(){
  int a=-1234567;
  for(int i=31;i>=0;i--){
    cout<<((a>>i&1)); //右移i位，输出第1位
    cout<<(i%4==0?" ":""); // 第四位添加一个空格
  }
  return 0;
}