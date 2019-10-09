#include<iostream>

class Display{
public:
  virtual void init()=0;
  virtual void write(char* pStr)=0;
};
class Monochrome:public Display{
  virtual void init();
  virtual void write(char* pStr);
};
class ColorAdapter:public Display{
public:
  virtual void write(char* pStr);
};
class SVGA:public ColorAdapter{
public:
  virtual void init();
};

void Monochrome::init(){
  std::cout<<"Monochrome init"<<std::endl;
}
void Monochrome::write(char* pStr){
  std::cout<<"Monochrome:"<<pStr<<std::endl;
}
void ColorAdapter::write(char* pStr){
  std::cout<<"ColorAdapter:"<<pStr<<std::endl;
}
void SVGA::init(){
  std::cout<<"SVGA init"<<std::endl;
}
void g(Display* d){
  d->init();
  d->write("hello.");
}
int main(){
  Monochrome mc;
  SVGA svga;
  g(&mc);
  g(&svga);
}