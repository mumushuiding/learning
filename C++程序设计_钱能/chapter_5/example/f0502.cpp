#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& a); // 引用是隐式指针，可以间接的访问向量
// void print(const vector<int>& a) // const 限制写操作
int main() {
  int aa[]={2,3,1,4}, bb[]={5,6,7,8};
  vector<int> a(aa,aa+4),b(bb,bb+4);
  print(a);
}
void print(vector<int>& a) { 
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}