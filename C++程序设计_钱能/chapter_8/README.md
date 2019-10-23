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
}; // 一定要有分号

void Date::set(int y,int m) {
  year=y;
  month=m;
}
```
成员函数
  * 写在类定义中的成员函数和具有内联性质
  * 可以重载
  * 操作符也可以重载，如： friend Date operator+(...){...} // 重载“+”操作符，添加friend是为了能访问私有数据

常成员函数： 只读成员函数,形式：void print() const{...}


## 8.6 静态成员 (Static Members)


### 8.6.1 静态数据成员

类的静态成员
  * 类独享的全局变量
  * 在类外分配空间和初始化

```
class Student{
  static int number; // number 为Student这个类独享的全局变量
};
int Student::number=0; // 静态数据成员在类外分配空间和初始化
```

### 8.6.2 静态成员函数 (Static Member Functions)

静态成员
  * 函数名前要加上关键字static
  * 不受对象牵制,可以使用类名加上域操作符来调用

```
class Student{
  static void print()
}
int main() {
  Student::print()
}
```
## 8.7 友元 (Friends)

