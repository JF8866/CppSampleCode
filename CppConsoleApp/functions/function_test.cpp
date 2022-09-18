//
//  function_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/14.
//

#include "function_test.hpp"
#include <iostream>

using namespace std;

double cube(double);
void countdown(int);
void subdivide(char ar[], int min, int max, int level);

const double* f1(const double ar[], int n);
const double* f2(const double [], int);
const double* f3(const double*, int);

//使用 typedef 简化复杂类型的声明
typedef const double* (*FuncArray[3])(const double*, int);//函数指针数组

void testFunction() {
//    countdown(5);
    
    //递归
    /*char ruler[66];
    for (int i = 0; i < 65; i++) {
        ruler[i] = ' ';
    }
    ruler[65] = '\0';
    for (int i = 1; i <= 6; i++) {
        subdivide(ruler, 0, 64, i);
        cout << ruler << endl;
    }*/
    
    //函数指针
    double (*fp)(double) = cube;
    auto fp2 = cube;//C++11
    cout << fp2(1.2) << endl;
    //包含函数指针的数组
    const double da[3] = {1.2, 2.3, 3.4};
    const double* (*funcs[3])(const double*, int) = {f1,f2,f3};
    const double* (*fun)(const double*, int) = funcs[0];
    FuncArray funcArr = {f1,f2,f3};
    //由于函数名和函数指针等价，因此下面的调用都是合法的
    cout << *fun(da, 3) << endl;
    cout << *funcs[1](da, 3) << endl;
    cout << *(*funcs[2])(da, 3) << endl;
    //指向函数指针数组的指针
    const double* (*(*pd)[3])(const double*, int) = &funcs;
    auto pd2 = &funcs;
}

const double* f1(const double da[], int n) {
    double d = 0.0;
    for (int i = 0; i < n; i++) {
        d += da[i];
    }
    return &d;
}

const double* f2(const double da[], int n) {
    double d = 1.0;
    for (int i = 0; i < n; i++) {
        d *= da[i];
    }
    return &d;
}

const double* f3(const double* da, int n) {
    double d = 0.0;
    for (int i = 0; i < n; i++) {
        d += da[i];
    }
    return &d;
}

double cube(double x) {
    return x * x * x;
}

//递归
void countdown(int n) {
    cout << "in  " << n << " " << &n << endl;
    if(n) {
        countdown(n - 1);
    }
    cout << "out " << n << " " << &n << endl;
}

void subdivide(char ar[], int min, int max, int level) {
    if(level == 0) return;
    int mid = (min + max) / 2;
    ar[min] = ar[mid] = ar[max] = '|';
    subdivide(ar, min, mid, level - 1);
    subdivide(ar, mid, max, level - 1);
}
