#include<fstream>
#include<iostream>
using namespace std;

int main(int argc,char** argv){
  ifstream in(argv[1]);
  try{
    if(!in) throw string(argv[1]);
  }catch(string s){
    cout<<"Error Opeing File "<<s<<"\n";
    return 1;
  }
  for (string s;getline(in,s);cout<<s<<endl);
}