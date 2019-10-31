// ====================
// f0204 求1000之内的”完数“,完数：所有因子相加
// ====================
#include<iostream>
using namespace std;
int main(){
  for (int i=1;i<=1000;i++){
    // 求因子和
    int sum=1;
    int j=i;
    int k=2;
    while(k<=j/2){
      if(j%k==0){ // 找到因子
        sum+=k;
      }
      k++;
    }
    // 判断
    if(sum==i){
      cout<<sum<<endl;
    }
  }
}