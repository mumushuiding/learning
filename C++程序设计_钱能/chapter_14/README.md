# 第14章 模板 (Templates)

模板编程: 用一种统一的方式来编程

## 14.1 函数模板 (Function Templates)

函数模板的定义形式:

template <类型参数表>

返回类型 函数模板名(数据参数表)
{
  函数模板定义体
}

例:

```
template<typename T>
void swap(T& a,T& b){
  T temp=a;a=b;b=temp;
}
int main(){
  int a=5,b=6;
  swap(a,b);
  std::cout<<"a="<<a<<"  b="<<b;
}
```

## 14.2 函数模板参数 (Function Template Parameters)

模板类型参数没有隐式转换之说,必须精确匹配.

可以指定模板的类型参数

```
template<typename T>
T const& max(const T& a, T const& b){
  return a<b?b:a;
}
int main(){
  int ia=3;
  double db=5.0;
  max<double>(ia,db); // 形参会首先隐式的转换成double
  max<double>(&ia,db); // 指针无法隐式的转换为double
}
```

对于引用型形参,数据实参应为左值表达式,不能是常量或字面值,例:

```
int ia=3;
swap(ia,7); // 错
```

## 14.3 类模板 (Class Templates)

