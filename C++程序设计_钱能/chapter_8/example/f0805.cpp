#include<iostream>
using namespace std;

class Point{
  int x,y;
public:
  void set(int a,int b) {x=a,y=b;}
  void print() const {cout<<"x="<<x<<",y="<<y<<endl;}
  friend Point operator+(const Point& a,const Point& b);
};

Point operator+(const Point&a,const Point& b){
  cout<<"i am call"<<endl;
  Point s;
  s.set(a.x+b.x+1,a.y+b.y);
  return s;
}

int main(){
  Point a,b;
  a.set(3,2);
  b.set(4,1);
  (a+b).print(); // + 操作符被重新定义了，所以结果是 (8,3) 而不是想象中的 (7,3)
}