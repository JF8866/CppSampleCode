//
//  cpp_func_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/20.
//

//C++有而C没有的函数特性:
//1、內联函数
//2、引用变量
//3、默认参数
//4、函数重载
//5、函数模版 更多细节参考《C++Primer Plus》(第6版)8.5

#include "cpp_func_test.hpp"
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct point {
    int x;
    int y;
};

//內联函数将整个定义放在本应提供原型的地方
inline double square(double x) {
    return x * x;
}

//传递引用，类似指针，即参数不是按值传递
void swapr(int&, int&);
//传递指针
void swapp(int*, int*);

void set_point(point&);
void show_point(const point&);
point& add_points(point&, const point&);

//默认参数只在原型中设置即可
char* left(const char*, int n = 1);

//函数模版，即通常所说的泛型函数
template <typename T>
void Swap(T&, T&);//因标准库中已有swap函数，所以这里使用大写开头

template <class T1, class T2>
auto ft(T1 x, T2 y) -> decltype(x + y) {
    //指定类型
    decltype(x + y) xpy = x + y;
    //如需多次使用该类型，可以使用 typedef
    typedef decltype(x + y) xpytype;
    xpytype xpy2 = x + y;
    //如果要返回 x + y 的类型，需要使用后置返回类型：
    //将返回类型声明为 auto，再在圆括号后面使用 -> decltype(expression)
    return xpy2;
}


void testCppFunc() {
    int a = 1;
    cout << a << endl;
    int& b = a;//必须在声明引用变量时进行初始化
    //引用更接近const指针
    //int* const b = &a;
    b++;
    cout << a << endl;
    int c = 100;
    b = c;//这里只是把c的值赋给了b，b仍然引用的是a，这时a的值也是100
//    b++;
    cout << "c=" << c << ", a=" << a << endl;
    
    int x = 1;
    int y = 2;
    cout << "x=" << x << ", y=" << y << endl;
    swapr(x, y);
    cout << "x=" << x << ", y=" << y << endl;
    swapp(&x, &y);
    cout << "x=" << x << ", y=" << y << endl;
    Swap(x, y);
    cout << "x=" << x << ", y=" << y << endl;
    
    //右值引用
    double &&rref = sqrt(36.0);
    cout << "rref=" << rref << endl;
    
    //虽然可以引用基本类型，但引用主要是用于结构体和类的
    point p1 = {0, 0};
    set_point(p1);
    point p2 = {1, 2};
    point p3 = add_points(p1, p2);
    show_point(p3);
    cout << "p1 address: " << &p1 << endl;
    cout << "p3 address: " << &p3 << endl;
    
    //默认参数
    char hello[6] = "hello";
    cout << "left(hello) " << left(hello) << endl;
    cout << "left(hello, 3) " << left(hello, 3) << endl;
    
    cout << ft(1, 2.3) << endl;
}

//
void swapr(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//
void swapp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void set_point(point &p) {
    p.x = 3;
    p.y = 4;
}

point& add_points(point &p1, const point &p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

void show_point(const point &p) {
    cout << "point(" << p.x << ", " << p.y << ")\n";
}

//截取字符串前n个字符组成的字符串
char* left(const char *str, int n) {
    size_t len = strlen(str);
    n = len < n ? (int)len : n;
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++) {
        p[i] = str[i];
    }
    p[n] = '\0';
    return p;
}

template <typename T>
void Swap(T &t1, T &t2) {
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

