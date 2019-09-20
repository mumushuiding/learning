#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  for(int i=1;i<=10;i++){
    // 输出若干空格 i-1
    for(int j=1;j<=i-1;j++){
      cout<<" ";
    }
    // 输出若干M  (10-i)*2+1
    for(int k=1;k<=(10-i)*2+1;k++){
      cout<<"M";
    }
    // 换行
    cout<<endl;

    // 第二种方法
    // cout<<setfill(' ')<<setw(i-1)<<""<<setfill('M')<<setw(21-2*i)<<""<<endl;
  }
}