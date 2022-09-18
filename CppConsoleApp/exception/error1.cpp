//
//  error1.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "error1.hpp"
#include <cfloat>

//C++以前的版本还支持函数声明可能抛出的异常
double hmean(double a, double b) noexcept(false)/* throw(bad_hmean) */ {
    if(a == -b) {
//        std::cout << "untenable arguments to hmean()\n";
//        std::abort();//终止程序
//        throw "bad hmean() arguments: a = -b not allowed";//抛出异常
        throw bad_hmean(a, b);
    }
    return 2.0 * a * b / (a + b);
}

bool hmean(double a, double b, double * ans) noexcept {
    if(a == -b) {
        *ans = DBL_MAX;
        return false;
    }
    *ans = 2.0 * a * b / (a + b);
    return true;
}

void testError1() {
    std::cout << hmean(1, 2) << std::endl;
    
    //捕获异常
    try {
        std::cout << hmean(1, -1) << std::endl;
    } catch (const char * s) {
        std::cout << s << std::endl;
    } catch (bad_hmean & ex) {
        ex.mesg();
        std::cout << ex.what() << std::endl;
    } catch(...) {//捕获未知的异常
        
    }
    
    //最初C++并没有 bad_alloc 这个异常，新版本的C++中可以通过 nothrow 让 new 在分配内存失败的情况下返回空指针
    int * pi = new (std::nothrow) int;
    int * pa = new (std::nothrow) int[500];
    
    double ans;
    std::cout << hmean(1, -1, &ans) << std::endl;
    std::cout << ans << std::endl;
    
    throw std::bad_exception();
}
