#include<iostream>
using namespace std;

struct Spoint
{
  int x,y;
};
class Cpoint{
  int x,y;
public:
  Cpoint(int ix=1,int iy=3){
    x=ix;
    y=iy;
  }
  static void print(Cpoint& c){
    cout<<"("<<c.x<<","<<c.y<<")";
  }
};

int main(){
  Cpoint c;
  c.print(c);

}