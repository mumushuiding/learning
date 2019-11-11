// =================
// f0305 加密
// =================
#include<iostream>
using namespace std;
const char key[]="1234567";

string encode(string& str){
  string result(str);
  for(int i=0;i<result.length();i++){
    result[i]+=(key[i%7]-'0'); // 能过减'0'转换成char 
    if (result[i]>'z'){
      result[i]-=91;
    }
  }
  return result;
}
string decode(string& str){
  string result(str);
  for(int j=0;j<str.length();j++){
    result[j]-=(key[j%7]-'0');
    if(result[j]<' '){
      result[j]+=91;
    }
  }
  return result;
}
int main(){
  string x="aa\\";
  cout<<"original: "<<x<<endl;
  x=encode(x);
  cout<<"encode: "<<x<<endl;
  cout<<"decode:"<<decode(x)<<endl;
  return 0;
}