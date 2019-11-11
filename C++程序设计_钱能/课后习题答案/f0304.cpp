// ====================
// f0304 汇总每月25的天数
// ====================
#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream in("abc.txt");
  string s;
  int sum=0;
  while(getline(in,s)){
    if(s.find("25")!=string::npos){
      if(s.find("*")!=string::npos){
        sum+=2;
      }else{
        sum++;
      }
    }
  }
  cout<<sum<<endl;
}