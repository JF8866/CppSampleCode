//
//  scope_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/21.
//

#include "scope_test.hpp"
#include <iostream>

using namespace std;

double globalVar = 0.3;//外部变量（不能在头文件中定义）
extern const int globalConst = 10;//类似Java的 public static final

static int fileScopeVar = 2022;//内部变量
const int fileScopeVar2 = 2023;//内部常量
static const int fileScopeVar3 = 2024;//内部常量

// 其他关键字
// volatile
// mutable

void update(double);
void local();
//static 标记的函数(原型和定义)是文件私有函数
static void strcount();


void testScope() {
    cout << "fileScopeVar = " << fileScopeVar << endl;
    
    cout << "globalVar is " << globalVar << endl;
    update(0.1);
    cout << "globalVar is " << globalVar << endl;
    local();
    cout << "globalVar is " << globalVar << endl;
    for (int i = 0; i < 3; i++) {
        strcount();
    }
}

void update(double dt) {
    extern double globalVar;
    globalVar += dt;
}

void local() {
    double globalVar = 0.8;
    cout << "local var is " << globalVar << endl;
    //局部变量与外部变量同名时，使用 :: 引用外部变量
    cout << "But globalVar is " << ::globalVar << endl;
}

static void strcount() {
    static int total = 0;//局部静态变量
    total += 1;
    cout << "total = " << total << endl;
}
