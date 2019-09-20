#include<iostream>
using namespace std;

int main(){
  for (int i=10;i<=20;i++){
    for(int j=1;j<=100;j++){
      if(i*j==150) goto End;
    }
  }
  End:
  cout<<"end";
}