//
//  StringBad.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/29.
//

#ifndef StringBad_hpp
#define StringBad_hpp

#include <stdio.h>
#include <iostream>

//知识点：动态内存和类（值得反复看）

//注：StringBad 是为了讲解动态内存（也可以说是新手容易犯的错误），并不是最佳实践

class StringBad {
private:
    char * str;
    int len;
    static int num_strings;//类的静态成员
public:
    StringBad(const char * s);
    StringBad();
    StringBad(const StringBad & sb);//定义一个显式的复制构造函数，进行深复制，避免多次释放同一块内存
    ~StringBad();
    StringBad & operator=(const StringBad &);//重载赋值运算符，进行深复制，避免多次释放同一块内存
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

void testStringBad();

#endif /* StringBad_hpp */
