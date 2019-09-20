#include<iostream>
using namespace std;

int main(){
  for(int i=1;i<=10;i++){
    // 输出若干空格 10-i
    for(int j=1;j<=10-i;j++){
      cout<<" ";
    }
    // 输出字符 2i-1
    // for(int k=1;k<=2*i-1;k++){
    //   cout<<char('A'+k-1);
    // }
    for(int ch='A';ch<='A'+2*i-1;ch++){
      cout<<char(ch);
    }
    // 换行
    cout<<endl;
  }
}