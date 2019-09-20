#include<fstream>
using namespace std;

int main(){
  // 定义变量，这种形式类似 int a(1) ,等价于 int a=1;
  ifstream in ("a.in"); // 读入文件
  ofstream out ("a.out"); // 输出文件
  for (string str;getline(in,str);){
    out<<str<<endl;
  }
}