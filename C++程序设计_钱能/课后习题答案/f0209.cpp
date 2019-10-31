// ========================
// f0209 STS
// ========================
#include<iostream>
using namespace std;
int main(){
  for(int i=10;i>=1;i--){
    cout<<string(10-i,' '); // 打印空格
    for(int j=1;j<=2*i-1;j++){
      if(j%2==0){
        cout<<"T";
      }else{
        cout<<"S";
      }
    }
    cout<<"\n";
  }
}