// ========================
// f0212 100元钱兑换问题
// ========================
#include<iostream>
using namespace std;

int main(){
  for(int i=1;i<(100-5-1)/10;i++){
    for(int j=1;j<(100-10-1)/5;j++){
      for(int k=1;k<100-10-5;k++){
        if(i*10+5*j+k==100){
          cout<<"10$="<<i<<",5$="<<j<<",1$="<<k<<endl;
          break;
        }
      }
    }
  }
}