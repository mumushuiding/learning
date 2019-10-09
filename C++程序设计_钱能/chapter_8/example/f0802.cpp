#include<iostream>
#include<iomanip>
using namespace std;

class Date{
  int year,month;
public:
  void set(int y,int m);
  void print();
};

void Date::set(int y,int m) {
  year=y;
  month=m;
}
void Date::print(){
  cout<<setfill('0');
  cout<<year<<"-"<<setw(2)<<month<<endl;
}

int main(){
  Date d;
  d.set(2000,6);
  d.print();

  Date* dp=new Date; // 对象指针
  dp->set(2001,5);
  dp->print();
}