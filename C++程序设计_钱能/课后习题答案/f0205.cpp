// ====================
// f0205 求3位对称素数
// ====================
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  for (int i=1;i<=9;i++){
    for(int j=0;j<=9;j++){
      int v=i*100+j*10+i; // 对称数
      // 判断是否是素数
      int k=2;
      while(k<=sqrt(v)){
        if(v%k==0){ // 不是素数
          break;
        }
        k++;
      }
      if (k>sqrt(v)) cout<<v<<endl;
    }
  }
}