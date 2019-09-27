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

