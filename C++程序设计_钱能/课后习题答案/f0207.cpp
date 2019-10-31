// ========================
// f0207 循环打印
// ========================
#include<iostream>
using namespace std;
int main(){
  for(int i=1,j=1;i<=19;++i,j=(i<10)?i:(20-i)){
    cout<<string(10-j,' ')+string(2*j-1,'%')+"\n";
  }
}