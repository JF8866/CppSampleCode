//
//  main.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/12.
//

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "string_test.hpp"
#include "struct_test.hpp"
#include "pointer_test.hpp"
#include "vector/vector_test.hpp"
#include "io/file_io_test.hpp"
#include "io/io_test.hpp"
#include "functions/function_test.hpp"
#include "functions/cpp_func_test.hpp"
#include "utils/convert_util.hpp"
#include "scope/scope_test.hpp"
#include "new_operator_test.hpp"
#include "class/stock.hpp"
#include "class/stack.hpp"
#include "class/time.hpp"
#include "class/vector.hpp"
#include "class/stonewt.hpp"
#include "class/StringBad.hpp"
#include "class/place_new.hpp"
#include "class/arraytp.hpp"
#include "class/pairs.hpp"
#include "inheritance/tabletennis.hpp"
#include "template/tmp2tmp.hpp"
#include "template/manyfrnd.hpp"
#include "friend/tv.hpp"
#include "exception/error1.hpp"
#include "exception/sales.hpp"
#include "RTTI/rtti1.hpp"
#include "STL/stl_test.hpp"
#include "useless.hpp"
#include "STL/lambda_test.hpp"

using namespace std;

void exception_handler() {
    cerr << "unexpected exception!!!\n";
    //将意外异常转换成 bad_exception，这样程序中就可以使用 bad_exception 来捕获意外的异常
    throw std::bad_exception();
}

//引用其他文件中定义的外部变量
extern double globalVar;

int main(int argc, const char * argv[]) {
    
//    set_unexpected(exception_handler);//macOS C++实现没有该方法
    set_terminate(exception_handler);
    
    // insert code here...
    int yams[3] = {6 ,7, 8};
    int total = sizeof(yams) / sizeof(int);
    cout << "main()" << endl;
    
    cout << "5 / 0 = " << (5 / 0) << endl;
    
//    testString();
    
//    testStruct();
    
//    testPointer();
    
//    testVector();
    
//    testFileIO();
    
//    testFunction();
    
//    testCppFunc();
    
//    testConvertUtil();
    
//    cout << "globalVar = " << globalVar << endl;
//    globalVar += 0.1;//修改其他文件中定义的外部变量
//    testScope();
    
//    testNewOperator();
    
//    testClass();
    
//    testStack();//类模版
//    testArrayTP();//类模版
//    testPair();//类模版
//    testTmp2tmp();//约束模版友元函数
//    testManyfrnd();//非约束模版友元函数
    
//    testOperatorOverload();//运算符重载
    
//    VECTOR::testVector();
    
//    testStonewt();//类的自动转换
    
//    testStringBad();
    
//    testPlaceNew();//定位 new 运算符
    
//    testInheritance();//继承
    
//    testTV();

//        testError1();
//    testSalesExcetion();
    
//    testRTTI1();
    
//    testSTL();
    
//    testIO();
//    tempFileNames();
    
//    testMoveConstructor();
    
//    testLambda();
//    testWrapper();
    testVarargs();
    
    return 0;
}


/* 多线程库支持由原子操作（atomic operation）库和线程支持库组成，其中原子操作库提供了头文件atomic，
 而线程支持库提供了头文件thread、mutex、condition_variable和future。

 头文件 chrono 提供了处理时间间隔的途径。

 头文件 tuple 支持模版 tuple，是广义的 pair 对象，可存储任意多个类型不同的值。
 
 头文件 regex 支持正则表达式。
 
 Boost Conversion 库中的 lexical_cast 可实现数值和字符串互转，其语法类似于 dynamic_cast。
 */
