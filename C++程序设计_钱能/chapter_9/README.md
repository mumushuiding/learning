# 第九章 对象生灭 (Object Birth & Death)

## 构造函数设计 (Constructor Design)

### 9.1.1 初始化要求

全局对象在创建时初始值为全0位

局部对象在创建时初始值为随机值

### 9.1.2 封装性要求 (Encapsulation Requirement)

```
struct Point{
  int x,y;
};

Point d= {2,3} // 正确
```

```
class Point{
  int x,y;
};

Point d={2,3} // 错

```

### 9.1.3 函数形式 (Function Form)

构造函数：反映对象创建的一般过程

```
class Cpoint{
  int x,y;
public:
  Cpoint(int ix,int iy){
    x=ix;
    y=iy;
  }
};
```

### 9.1.4 无返回值 (Non Return-Type)

构造函数不论成功失败都不返回值

### 9.1.6 一次性对象 (Only-One-Time Object)

创建对象如果不给出对象名，会产生一个无名对象

```
cout<<Date(2003,12,23);  // 该对象在做了<<操作后便消失了
```

## 9.2 构造函数的重载 （Constructor Overload）

### 9.2.1 重载构造函数 (Overload Constructor)

```
class Date{
  int year,month,day;
public:
  Date(int y=200,int m=1,int d=1); // 设置默认参数
  Date(const string& s); //重载
};
```

### 9.2.2 无构造函数 (Non-Parameter Constructor)

### 9.3 类成员初始化 (Class Member initialization)

类新建时会先调用无参构造函数

```
class StudentID{
  int value;
public:
  StudentID(int id=0) { // 参数默认，这样无参函数的调用也能通过
    value=id;
    cout<<"Assgining student id "<<value<<endl;
  }
};
class Student{
  string name;
  StudentID id;
public:
  Student(string n="noName",int ssID=0) {
    cout<<"Constructing student " +n+ "\n";
    name=n;
    StudentID id(ssID);
  }
};

int main(){
  Student s;
  Student s1("Rand",30);
}
```

结果：

```
Assgining student id 0
Constructing student noName
Assgining student id 0
Assgining student id 0
Constructing student Rand
Assgining student id 30
```
### 9.3.3 成员的初始化 (Initializing Members)

在构造函数的参数列表右括号后面，花括号前面，可以用冒号引出构造函数的调用表，该调用表可以省略类型名称，但却行创建对象之职

```
class StudentID{
  int value;
public:
  StudentID(int id=0) {
    value=id;
    cout<<"Assgining student id "<<value<<endl;
  }
};

class Student{
  string name;
  StudentID id;
public:
  Student(string n="no name",int ssID=0):id(ssID),name(n){
    cout<<"Constructing student "<<n<<endl;
  }
};

int main(){
  Student s;
  cout<<endl;
  Student("lilei",18);
}
```

输出：

```
Assgining student id 0
Constructing student no name

Assgining student id 18
Constructing student lilei
```

## 9.4 构造顺序 (Constructing Order)

### 9.4.1 局部对象 (Local Objects)

根据定义顺序来决定对象创建的顺序

静态对象只创建一次。

### 9.4.2 全局对象 (Global Objects)

全局对象的创建没有明确的控制流中表明其顺序，在C++中没有规定它的创建顺序。

### 9.4.3 成员对象 (Member Objects)

成员对象以其在类中声明的顺序构造。

### 9.4.4 构造位置 (Constructing Position)

构造位置：
  * 放在全局数据区: 全局对象、常对象、静态对象
  * 放在栈区: 局部对象
  * 放在动态内存区
  * 放在特殊地址空间
  
## 9.5 拷贝构造函数 (Copy Constructor)

### 9.5.1 对象本体与实体 (Object Realty & Entity)

```
class Person{
  char* pName;
public:
  Person(char* pN="noName") {
    cout<<"Constructing "<<pN<<endl;
    pName=new char[strlen(pN)+1];
    if(pName) strcpy(pName,pN);
  }
  ~Person(){ // 析构函数专门做对象销毁时的善后工作
    cout<<"Destructing "<<pName<<endl;
    delete[] pName;
  }
};
int main(){
  Person p1("Randy");
}
```


## 9.6 析构函数 (Destructors)

在类名前加~的无参构造函数为析构函数

浅拷贝：对象本体与对象实体一致时

深拷贝：对象本体与对象实体不一致时，需要动态分配内存。

系统不会自动为对象做内存释放工作

人为的动态内存释放工作由析构函数来完成

```
class Person{
public:
  Person(){}
  ~Person(){}
}
```

## 9.7 对象转型与赋值 (Object Conversion & Assignment)

对于类类型，其自动转换的功能必须编程实现

### 9.7.2 对象赋值 (Object Assignment)

默认的赋值操作符只管对象本体的复制

如果对象之间要做深拷贝的话，则必须自定义赋值操作符。

自定义赋值操作必须注意，要先将原来对象的资源释放掉，然后再深拷贝。

```
class Person{
  char* pName;
public:
  Person(char* pN="noName"){ // 构造函数
    cout<<"Constructing "<<pN<<endl;
    pName=new char[strlen(pN)+1];
    if(pName) strcpy(pName,pN);
  }
  Person& operator=(Person& s){ // 重载操作符“=”的定义
    cout<<"Assigning "<<s.pName<<endl;
    if (this==&s) return s; //  关键字 this 表示当前对象的地址
    delete[] pName;  // 先将原来对象的资源释放掉
    pName=new char[strlen(s.pName)+1];
    if(pName) strcpy(pName,s.pName);
    return *this;

  }
  ~Person(){ // 析构函数
    cout<<"Destructing "<<pName<<endl;
    delete[] pName;
  }
};

int main(){
  Person p1("Tom");
  Person p2("Lily");
  p2=p1;
}
```