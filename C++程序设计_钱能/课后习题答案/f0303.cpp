// ====================
// f0303 对向量求标准差
// ====================
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
  int a[10]={6,3,7,1,4,8,2,9,11,5};
  double average; // 均值
  double s; //均方差
  vector<int> va(a,a+10);
  int n=va.size();
  for(int i=0;i<n;i++){
    average+=a[i];
  }
  average=average/n; // 求平均数
  for(int i=0;i<n;i++){
    s+=((va[i]-average)*(va[i]-average));
  }
  s=sqrt(s/n);
  cout<<s<<endl;
}