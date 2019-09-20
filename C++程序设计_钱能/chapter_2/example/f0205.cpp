#include<iostream>
using namespace std;

int main(){
  int sum=0,i=1;
  // while (i<=100)
  // {
  //   sum+=i++;
  // }

  do{
    sum+=i++;
  }while(i<=100);
  cout<<sum<<endl;
}