// ====================
// f0203 计算水仙花数
// ====================
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  for(int i=1;i<=9;i++){//遍历百位数
    for(int j=0;j<=9;j++){ // 遍历十位
      for(int k=0;k<=9;k++){  // 遍历个位
        int v1=i*100+j*10+k;
        int v2=i*i*i+j*j*j+k*k*k;
        if(v1==v2){
          cout<<v1<<endl;
        }
      }
    }
  }
  return 0;
}