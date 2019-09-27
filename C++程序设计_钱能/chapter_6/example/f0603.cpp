#include<iostream>
using namespace std;

inline bool isnumber(char); // 内联声明

int main(){
  char c;
  while(cin>>c && c!='\n') {
    if (isnumber(c)) cout<<"is number \n";
    else cout<<"not number \n";
  }
}
bool isnumber(char ch){
  return ch>='0'&&ch<='9'?1:0;
}