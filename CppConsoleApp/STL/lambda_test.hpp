//
//  lambda_test.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/17.
//

#ifndef lambda_test_hpp
#define lambda_test_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

template<typename T>
T use_f(T v, function<T(T)> f) {
    static int count = 0;
    count++;
    cout << " use_f count = " << count << ", &count = " << &count << endl;
    return f(v);
}

class Fp {
private:
    double z_;
public:
    Fp(double z = 1.0) : z_(z) {}
    double operator()(double p) { return z_ * p; }
};


class Fq {
private:
    double z_;
public:
    Fq(double z = 1.0) : z_(z) {}
    double operator()(double q) { return z_ + q; }
};

void testLambda();

//包装器
void testWrapper();


//可变参数模版
void show_list();

template<typename T>
void show_list(T value);

template<typename T, typename... Args>
void show_list(T value, Args... args);

void testVarargs();

#endif /* lambda_test_hpp */
