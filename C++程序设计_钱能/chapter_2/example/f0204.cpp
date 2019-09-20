#include<iostream>
using namespace std;

int main(){
  char grade='C';
  switch (grade)
  {
    case 'C':cout<<"60----79\n";
    case 'B':cout<<"80----89\n";break; // 缺少break会全部执行
    case 'A':cout<<"90---100\n";
    default:
      cout<<"end"<<endl;
  }
}