#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int bitSum(int a) {
  int sum=0;
  for(int x=a;x;x/10) {
    sum+=x%10;
  }
  return sum;
}
bool lessThan(int a,int b){return bitSum(a)<bitSum(b);}
int main(){
  int a[]={33,24,12};
  vector<int> aa(a,a+3);
  sort(aa.begin(),aa.end());
  for(int i=0;i<aa.size();i++){
    cout<<aa[i]<<" ";
  }
}
