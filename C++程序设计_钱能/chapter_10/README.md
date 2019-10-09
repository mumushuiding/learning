# 第10章 继承 (Inheritance)

继承：类之间的上下级关系

继承：就是让子类继承父类public和 protected属性和操作，子类可以声明新的属性和操作。

继承类型：
  * 公有继承 public： 只能访问公有和保护的属性和操作
  * 保护继承 protected: 基类的 public 变成 protected , protected 保护不变
  * 私有继承 private: 基类的公有和保护属性和操作都变成子类私有的，它的派生类无法继承

基类也称超类

派生类也称子类



## 10.1 继承结构 (Inheritance Structure)

### 10.1.1 类层次结构 (Class Hierarchy Structure)

### 10.1.2 派生类对象结构 (Derived Object Structure)

派生类继承的方式是： class B:public BaseClass{};

## 10.2 访问父类成员 (Access Father's Member)

### 10.2.1 继承父类成员 (Inherit Father's Member)

protected 访问控制符：保护成员不能进行公共访问，但可以被类内部的成员函数访问。

### 类内访问控制 (Access Control in Class)

## 10.3 派生类的构造 (Constructing Derived Classes)

### 10.3.1 默认构造 (Default Construction)

派生类若未定义构造函数，会挂靠默认的无参构造函数

派生类的默认无参构造函数会首先调用父类的无参构造函数。

若父类定义了有参构造函数（因此没有默认无参构造函数），又没有重载定义无参构造函数，会编译错误。

### 10.3.2 自定义构造 (User-Defined Construction)

可以在派生类的构造函数中规定调用基类构造函数的形式。

### 10.3.3 拷贝构造与赋值 (Copy Construction & Assignment)

### 10.3.4 对象构造顺序 (Object Constructing Order)

对象构造顺序：
  * 先调用基类的构造函数
  * 接下来给自身的对象本体分配空间
  * 构造对象成员 （若有多个对象，按声明顺序）
  * 调用自身的构造函数体

## 10.4 继承方式 (Inheritance Mode)

### 10.4.1 继承访问控制 (Inheriting Access Control)

### 10.4.2 调整访问控制 (Adjusting Access Control)

## 10.5 继承与组合 (Inheritance & Composition)

### 10.5.1 对象结构 (Object Structure)

组合 (composition): 类含有对象成员

### 10.5.2 性质差异 (Character Differentiation)

### 10.5.3 对象分析 (Object Analysis)

### 10.5.4 继承设计 (Inheritance Design)

## 10.6 多继承概念 (Multi-Inheritance Concept)

### 10.6.1 多继承结构 (Multi-Inheritance Structure)

多重继承： 一个类从多个基类派生

### 10.6.2 基类成员名冲突 (Base-Class Member Name Collision)

多继承时，基类属性名冲突时,需在冲突名称前缀以说明基类：

```
int main() {
  SleeperSofa ss;
  ss.Sofa::setWeight(20);
}
```

### 10.6.3 基类分解 (Base-Class Decomposition)

## 10.7 多继承技术 (Multi-Inheritance Techonology)

### 10.7.1 虚拟继承 (Virtual Inheritance)

例如B1、B2继承A,而C多重继承B1、B2,如果普通继承则C包含两份A的拷贝，分别来自于B1、B2,而虚拟继承只包含一份A的拷贝。

### 多继承对象构造顺序 (Multi-Inheritance Object Constructing Order)

多继承的构造函数被调用顺序:
  * 虚拟基类
  * 非虚拟基类
  * 成员对象
  * 类自身







