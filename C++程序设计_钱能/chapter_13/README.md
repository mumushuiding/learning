# 第13章 抽象类 (Abstract class)

## 13.1 抽象基类 (Abstract Base-Class)

定义抽象类就是在类定义中至少声明一个纯虚函数，例：

```
virtual void display(double amount) = 0; // 纯虚函数 
```

纯虚函数一旦声明，就不用定义.具体定义由子类覆写.

抽象类是不允许有实例对象的.

## 13.2 抽象类与具体类 (Abastract & Concrete Classes)

## 13.3 深度隔离的界面 (Deeply Parted Interface)

## 13.4 抽象类做界面 (Abstract Class As interface)

抽象类是类层次结构的基类,基类的指针操作可以表现多态行为,而且抽象类只提供纯虚函数,不牵扯成员函数定义,不提供任何私有数据,干净利落.

## 13.5 演绎概念设计 (Deducting Concept Design)


## 13.7 手柄 (Handle)

