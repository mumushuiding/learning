// ==================
// f0206 猴子吃桃问题
// ==================
#include<iostream>
int main(){
  int d=10;
  int sum=1;
  while(d>1){
    d--;
    sum=(sum+1)*2;
  }
  std::cout<<sum;
  return 0;
}