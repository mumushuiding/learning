// ========================
// f0208 循环打印
// ========================
#include<iostream>
using namespace std;
int main(){
  for(int i=1;i<=10;i++){
    cout<<string(10-i,' ')+string(i,'#')+string(4,' ')+string(i,'$')+"\n";
  }
}