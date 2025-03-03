# c++学习指南

------

### 1.学习书目：

Accelerated C++,C++ Primer ,The C++ Programming Language 

### 2.常用网站：

http://en.cppreference.com/w/

### 3.深入理解计算机系统

推荐阅读：《csapp》 《程序员的自我修养》

《effective c++》

### 4.stl源码

源码之下，了无秘密。

《stl源码剖析》

《effecive stl》

### 5.侯捷 

### 6.开始学习

#### 1.面向对象编程 

project oriented language 

object = attribute + service（数据+操作）

：colon  ；semicolon

encapsulation 打包

#### 2. ::（作用域解析运算符）的作用

```c++
//访问全局变量
#include <iostream>

int var = 10; // 全局变量

void func() {
    int var = 20; // 局部变量
    std::cout << ::var <<' '<<var<< std::endl; // 输出全局变量的值，即10
}

int main() {
    func();
    return 0;
}
```

```c++
//指定类的成员
#include <iostream>

class MyClass {
public:
    void myFunction(); // 声明成员函数
};

void MyClass::myFunction() { // 定义成员函数
    std::cout << "Member function called." << std::endl;
}

int main() {
    MyClass obj;//创建了一个Myclass类型的对象obj 
    obj.myFunction();//通过对象obj调用函数，注意此处函数必须为公共成员函数，否则编译器将报错 
    return 0;
}

```

```c++
//访问命名空间中的变量
#include <iostream>

namespace myNamespace {
    int var = 30;
}

void func() {
    std::cout << myNamespace::var << std::endl; // 访问命名空间中的变量
}

int main() {
    func();
    return 0;
}

```

```c++
//访问类成员 
#include <iostream>

class MyClass {
public:
    static int staticVar;
    enum EnumValue { VALUE = 10 };
};

int MyClass::staticVar = 5; // 静态成员变量定义

void func() {
    std::cout << MyClass::staticVar << std::endl; // 访问静态成员变量
    std::cout << MyClass::VALUE << std::endl; // 访问枚举值
}

int main() {
    func();
    return 0;
}

```

```c++
//访问类型别名 
#include <iostream>

template<typename T>
class MyClass {
public:
    typedef T Type;
};

void func() {
    MyClass<int>::Type var = 42; // 访问类型别名 
    std::cout << var << std::endl;
}

int main() {
    func();
    return 0;
}
 
```

```c++
//嵌套类 
#include <iostream>

class OuterClass {
public:
    class InnerClass {
    public:
        void innerFunction();
    };
};

void OuterClass::InnerClass::innerFunction() {
    std::cout << "Nested class function called." << std::endl;
}

int main() {
    OuterClass::InnerClass innerObj;
    innerObj.innerFunction();
    return 0;
}

```

#### 3.namespace

命名空间是组织代码和避免名称冲突的机制。

#### 4.std

​	std是standard library 的命名空间，包含大量标准库组件（iostream，string，vector,map,sort，find以及许多其他工具和类）。

​	在没有歧义的情况下，可以在程序开头用：

```c++
using namespace std
```

#### 5.endl

```c++
endl 等价于"\n"
```

#### 6.引用

##### 1 定义

##### 引用是另一个变量的别名，对引用的任何操作都会影响到原变量

##### 2  对基本变量的引用

```c++
#include <iostream>

int main() {
    int a = 10;
    int& refA = a; // refA 是对 a 的引用

    refA = 20; // 通过引用修改 a 的值
    std::cout << "a 的值: " << a << std::endl; // 输出 20

    return 0;
}

```

##### 3 作为函数的参数

```c++
#include <iostream>

void increment(int& num) {
    num++; // 直接修改传入的参数
}

int main() {
    int b = 5;
    increment(b); // b 的值将被增加
    std::cout << "b 的值: " << b << std::endl; // 输出 6

    return 0;
}

```

##### 4.形成返回引用的函数

```c++
#include <iostream>

int& max(int& x, int& y) {
    return (x > y) ? x : y; // 返回两个数中较大的一个的引用
}

int main() {
    int c = 15;
    int d = 20;
    max(c, d) = 25; // 将 c 和 d 中较大的数设置为 25
    std::cout << "c 的值: " << c << std::endl; // 输出 15 或 25
    std::cout << "d 的值: " << d << std::endl; // 输出 20 或 25

    return 0;
}

```

##### 5  引用数组

```c++
#include <iostream>

int main() {
    int arr[3] = {1, 2, 3};
    int (&refArr)[3] = arr; // refArr 是对数组 arr 的引用

    refArr[0] = 10; // 通过引用修改数组元素
    std::cout << "arr[0] 的值: " << arr[0] << std::endl; // 输出 10

    return 0;
}

```

#### 7.vector容器

##### 1.使用

```c++
#include <vector>
//创建vector
std::vector<int> myvector;//创建一个储存整数的空vector
std::vector<int> myvector={1,2,3,4};//创建vector
std::vector<int> myvector(5);//创建一个可以储存5个整数（默认初始化为0）的vector
std::vector<int> myvector(5,10);//创建一个储存5个整数（初始化为10）的vector
//添加元素
myvector.push_back(7);//将整数7添加到vector的末尾
//访问元素
int x=myvector[0];//获取第一个元素
int y=myvector.at(1);//获取第二个元素
//获取vector大小
int len=myvector.size();
//迭代访问
for(auto it=myvector.begin();it!=myvector.end();it++){//使用迭代器遍历vector中的元素/
    std::cout<<*it<<std::endl;
}
/
for(int element:vector){//使用范围循环
    std::cout<<element<<std::endl;
}
//删除元素
myvector.erase(myvector.begin()+2);//shna'h
```

