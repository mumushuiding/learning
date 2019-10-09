# 第七章 程序结构

## 7.1 函数组织 (Function Organization)

### 7.1.1 程序构成 (Program Composition)

程序的组织方法是基于过程的。

函数是组成程序框架的基本单位

程序结构描述：
  * 树状结构：从程序的调用关系来说，呈树状结构
  * 网状结构：从函数模块依赖关系来说，呈网状结构

### 7.1.2 程序文件拆分 (Split up Program File)

程序如果有好几十个函数，那就要分类，把其分成几个程序文件。

## 7.2 头文件 (Header Files)

函数必须先声明，才能调用

函数声明的次数不受限制

### 7.2.1 原始头文件 (Original Header File)

头文件： 包含函数声明的文件

在程序开端使用 #include 语句包含它，这样就无须声明了

### 7.2.3 头文件内容

函数声明， void fn()

全局数据声明, extern int n

类型声明, class A

类型定义, class A{...}

模板声明 template<class T> class A {...}

名空间定义 namespace N{...}

预编译指令, #include<iostream>

注释， //



## 7.3 全局数据 (Global Data)

全局数据就是在任何函数的外部声明或定义的。

全局数据只能定义一次，以 extern 开头

## 7.4 静态数据 (Static Data)

static定义的函数和变量只在 ***本文件*** 范围内可见

静态局部变量只会被初始化一次

```
int main(){
  func();
  func();

}
void func(){
  static int a=2;
  a+=2;
  cout<<a<<endl;
}
```
结果为：4,6 而不是想象中的 4,4 ,说明静态变量只在第一次调用func时初始化


## 7.5 作用域与生命期 (Scopes & Lifetime)

### 7.5.1 作用域 (Scopes)

C++的作用域有：
  * 全局作用域（文件作用域）：全局可见
  * 函数作用域：参数函数数内可见
  * 函数原型作用域
  * 类作用域：与名空间机制类似
  * 局部作用域

当全局j和局部j发生冲突时，默认访问局部j,但 ::j 可以访问全局j

### 7.5.2 生命期 (LifeTime)

生命期是指一个实体产生后，存活时间的度量。

静态局部数据的生命周期一直延续到程序运行结束

另有一种动态生命期，这种生命期是由于new申请到内存空间，直到人为使用delete语句释放该空间，生命周期才结束。

## 7.6 名空间 (Namespace)

名空间机制：一个名称必须在使用的域中明确声称其使用的“空间名”，才能在域中默认地使用该名称

### 7.6.1 名空间的概念 (Namespace Concept)


### 7.6.2 名空间的组织 (Namespace Organization)

### 7.6.4 数据名冲突 (Data Name Clash)

### 7.6.5 名空间的用法 (Using namespace)

使用名空间，可以把名空间中所有的名称一并默认，即：

      using namespace std;

局部默认名空间：

      using std::cout;

## 7.7 预编译 (Pre-Compilation)

### 7.7.1 #include 指令 (#include)

include 指令指示预编译将包含的头文件的内容附加在程序文件中，以参加编译：
  * 头文件由C++提供，用尖括号 (<>) 括起来，直接在默认路径搜索头文件
  * 如果是自定义文件则用双引号 (""),先在源程序文件径中搜索文件。

### 7.7.2 条件编译指令 (Condition Compiling Directive)

条件编译的作用是根据条件选择加载头文件

```
#ifdef _USE_OLD
# include<old>
#else
# include<new>
#endif
```

### 7.7.3 头文件卫士 (Header File Safeguard)

头文件卫士的目的是要保护嵌套的包含指令中的内部链接属性不被重复定义

```
#ifndef DATE
  #define DATE
  struct Date{
    int year,month
  };
#endif
```

### 7.7.4 #define 指令

#define 称为宏定义指令