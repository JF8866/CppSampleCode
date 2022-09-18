//
//  error1.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#ifndef error1_hpp
#define error1_hpp

#include <stdio.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>
//头文件 stdexcept 定义了其他几个异常类。首先，该文件定义了 logic_error 和 runtime_error 类，它们都是以公有方式从 exception 派生而来

//定义一个异常类，throw 可以抛出任何类型的异常，C++标准库也提供了一些异常类
class bad_hmean : public std::exception {
private:
    double v1;
    double v2;
public:
    bad_hmean(int a = 0, int b = 0) : v1(a), v2(b) {}
    //重写 exception 类的 what 方法
    const char * what() {
        return "bad arguments to hmean()";
    }
    void mesg();
};

inline void bad_hmean::mesg() {
    std::cout << "hmean(" << v1 << ", " << v2 << "): invalid arguments: a = -b\n";
}

double hmean(double a, double b) noexcept(false);
bool hmean(double a, double b, double * ans) noexcept;


void testError1();

#endif /* error1_hpp */
