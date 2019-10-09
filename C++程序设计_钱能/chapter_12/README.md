# 第12章 多态 (Polymorphism)

多态：操作随着所传递对象类型的不同做出不同的反应

不能使用基类给子类赋值，因为基类不含子类全部的信息。

子类可以覆写基类的方法

使用虚函数实现多态，一旦基类标记成虚函数，继承类同名函数也会变成虚函数，例：

```
class Student{
public:
  virtual void calc(){ // 使用虚函数实现多态机制
    cout<<"student tuition"<<endl;
  }
};
class Graduate:public Student{
public:
  void calc(){cout<<"graduate tuition"<<endl;}
};

void fn(Student& x){x.calc();} // x必须为基类的引用性形参，否则不会有多态


int main(){
  Student s;
  Graduate gs;
  vector<Student*> v;
  v.push_back(&s);
  v.push_back(&gs);
  
  for(int i=0;i<v.size();i++){
    fn(*v[i]);
  }
}
```

仅仅对于对象的指针和引用的间接访问，才会发生多态现象。

只有在加上virtual的成员函数，才被编译做滞后处理，滞后的间接效应解决了重要的多态问题。

派生类和基类的成员函数都返回自己对象的指针，但仍然具有虚函数的作用。

```
class Base{
public:
  virtual Base* afn(){
    cout<<"In Base Class\n";
    return this;
  }
};
class Sub:public Base{
public:
  Sub* afn(){
    cout<<"In Sub class\n";
    return this;
  }
};
void test(Base& x){
  Base* b;
  b=x.afn();
}
int main(){
  Base b;
  Sub s;
  test(b);
  test(s);
}
```

只有类的成员函数才能声明为虚函数

静态成员函数不能是虚函数

内联函数不能是虚函数

构造函数不能是虚函数

析构函数通常声明为虚函数

## 12.5 精简共性的类 Simplify Class with Generality

## 12.6 多态编程 Polymorphic Programming

### 12.6.1 共同基类方案 (Shared Base-Class Scheme)

共同基类是一个所有派生类共性的抽象.

## 12.7 类型转换 (Type Conversions)
