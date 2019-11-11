// =================
//  f0404 找出积为16!的数对
// =================
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
  double a=1.0;
  // 计算16!
  for(int i=2;i<=16;i++) a*=i;
  // 读取文件
  ifstream in("abc.txt");
  string s;
   // 逐行处理数据
  while(getline(in,s)){ // 当字符串数字位数超过6位时存在精度丢失问题
    double mut=1,p=1;
    for(istringstream sin(s);sin>>p;mut*=p);
    if(abs(mut-a)<1e-5){
      cout<<s<<endl;
    }

  }
  return 0;
}