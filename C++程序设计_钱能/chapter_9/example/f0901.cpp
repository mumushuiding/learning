#include<iostream>
using namespace std;

struct Spoint
{
  int x,y;
};
class Cpoint{
  int x,y;
public:
  Cpoint(int ix=0,int iy=0){
    x=ix;
    y=iy;
  }
  static void print(Cpoint& c){
    cout<<"("<<c.x<<","<<c.y<<")";
  }
};

int main(){
  Spoint s={2,3};
  Cpoint c(4,5);
  cout<<s.x<<endl;
  c.print(c);

}