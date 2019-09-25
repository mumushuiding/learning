#include<iostream>
#include<vector>
using namespace std;

int main() {
  int a[7]={1,2,3,4,5,6,7};
  vector<int> va(a,a+7);
  vector<int> vb(va.begin(),va.begin()+3);
  for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  for (vector<int>::iterator it=va.begin();it!=va.end();++it){
    cout<<*it<<" ";
  }
  cout<<endl;
  for(vector<int>::iterator it=vb.begin();it!=vb.end();it++){
    cout<<*it<<" ";
  }
}