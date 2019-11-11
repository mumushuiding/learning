#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
  ifstream in("a.txt");
  for(string s;getline(in,s);){
    cout<<s<<endl;
    int a,sum=0;
    for(istringstream sin(s);sin>>a;sum+=a);
    cout<<sum<<endl;
  }
}