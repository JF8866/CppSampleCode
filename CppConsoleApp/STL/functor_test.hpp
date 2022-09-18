//
//  functor_test.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/12.
//

#ifndef functor_test_hpp
#define functor_test_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <string>

//函数对象，重载 () 运算符，就可以像调用函数一样使用类对象

class Linear {
private:
    double slope;
    double y0;
public:
    Linear(double s1_ = 1, double y_  = 0) : slope(s1_), y0(y_) {}
    double operator()(double x) {
        std::cout << x << std::endl;
        return y0 + slope * x;
    }
};


//
template<typename T>
class TooBig {
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};



void testFunctor();

#endif /* functor_test_hpp */
