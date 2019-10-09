# 第8章 类 (Classes)

## 8.1 从结构到类 (From Structure to Class)

struct: 可以定义数据的复合，不能定义操作

```
struct Date{
  int year;
  int month;
}
```

class: 不但可以定义数据的复合，还能定义数据的操作

```
class Date{
  int year,month;
public:
  void set(int y,int m);
  void print();
  void print1() const; // 常成员函数，一目了然不会改变对象值
}; // 一定要有分号

void Date::set(int y,int m) {
  year=y;
  month=m;
}
void Date::print(){
  cout<<setfill('0');
  cout<<year<<"-"<<setw(2)<<month<<endl;
}
```

## 8.3 操作符 (Operators)

可以对操作符进行函数那样的定义，之后，就可以自由使用该操作符了

不能新创操作符，然后定义

“::”、“.”、“.*” 不能重载

“?:”、sizeof、typeof也不允许重载

操作符的重载只能针对自定义类型

```
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
```

## 8.5 屏蔽类的实现 (Shield Class Implementations)

在头文件里定义类 (相当于java的 interface 文件),然后在 cpp 文件里定义类的实现，这样可以屏蔽类的实现

## 8.6 静态成员 (Static Members)


### 8.6.1 静态数据成员

类的静态成员，是这个类独享的全局变量

```
class Student{
  static int number; // number 为Student这个类独享的全局变量
};
int Student::number=0; // 静态数据成员在类外分配空间和初始化
```

### 8.6.2 静态成员函数 (Static Member Functions)

静态成员函数名前要加上关键字static

静态成员函数不受对象牵制,可以使用类名加上域操作符来调用

```
class Student{
  static void print()
}
int main() {
  Student::print()
}
```
## 8.7 友元 (Friends)

