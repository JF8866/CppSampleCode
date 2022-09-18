//
//  arraytp.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/6.
//

#ifndef arraytp_hpp
#define arraytp_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>


//模版中的 n 称作表达式参数，可以是整型、枚举、引用或指针，比如 double d 不是合法的表达式参数，而
//double * pd 是合法的。模版代码不能修改参数值，也不能使用参数的地址，所以在 ArrayTP 模版中不能
//使用诸如 n++ 和 &n 等表达式。用作表达式参数的值必须是常量表达式。

/* 与Stack中使用的构造函数方法相比，这种改变数组大小的方法有一个优点。构造函数方法使用的是通过new和delete管理的堆内存，而表达式参数方法使用的是为自动变量维护的内存栈。这样，执行速度将更快，尤其是在使用了很多小型数组时。 表达式参数方法的主要缺点是，每种数组大小都将生成自己的模板。也就是说，下面的声明将生成两个独立的类声明：
ArrayTP<double, 12> arr1;
ArrayTP<double, 13> arr2; */
template<typename T, int n>
class ArrayTP {
private:
    T arr[n];
public:
    ArrayTP(){}
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
};

template<typename T, int n>
ArrayTP<T, n>::ArrayTP(const T & v) {
    for (int i = 0; i < n; i++) {
        arr[i] = v;
    }
}

template<typename T, int n>
T & ArrayTP<T, n>::operator[](int i) {
    if(i < 0 || i >= n) {
        std::cerr << "Error in array limits: " << i << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template<typename T, int n>
T ArrayTP<T, n>::operator[](int i) const {
    if(i < 0 || i >= n) {
        std::cerr << "Error in array limits: " << i << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

void testArrayTP();

#endif /* arraytp_hpp */
