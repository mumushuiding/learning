#include<iostream>

template<typename T>
T const& max(const T& a, T const& b){
  return a<b?b:a;
}
int main(){
  int ia=3;
  double db=5.0;
  std::cout<<max<double>(ia,db)<<std::endl;
}