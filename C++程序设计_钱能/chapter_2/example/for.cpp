#include<iostream>
using namespace std;

int main(){
  int sum=0;
  // for (int i=1;i<=100;i++){ // 常规表示for循环
  //   sum+=i;
  // }

  // for(int i=100;i>=1;i--){ // 递减表示
  //   sum+=i;
  // }

  // for(int i=1;i<=100;) { // 状态修正省略
  //   sum+=i++;
  // }

  // for(int i=1;;i++){ // 条件判断省略
  //   sum+=i;
  //   if (i>100) break;
  // }

  int i=1;
  for(;i<=100;i++){ //初始值省略
    sum+=i;
  }
  cout<<sum<<endl;
}
