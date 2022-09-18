//
//  String.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/30.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <iostream>

//知识点：动态内存和类（值得反复看）

//改进后的新 String

class String {
private:
    char * str;
    int len;
    static int num_strings;//类的静态成员
    static const int CINLIM = 80;//cin input limit
public:
    String(const char *);
    String();
    String(const String &);//定义一个显式的复制构造函数，进行深复制，避免多次释放同一块内存
    ~String();
    int length() const { return len; }
    String & operator=(const String &);//重载赋值运算符，进行深复制，避免多次释放同一块内存
    String & operator=(const char *);
    // String means("might");
    // means[4] = 'r';
    char & operator[](int i);//这个版本还可以实现赋值功能
    const char & operator[](int i) const;//这个版本只能读取字符
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);
    /* 将比较函数作为友元，有助于将 String 对象与C字符串进行比较，例如，假设 answer 是 String 对象，则 "love" == answer 将被转换为 operator==("love", answer) 然后编译器将使用对应的构造函数将代码转换为 operator==(String("love"), answer) */
    friend bool operator<(const String & st1, const String & st2) {
        return strcmp(st1.str, st2.str) < 0;
    }
    friend bool operator>(const String & st1, const String &st2) {
        return st2 < st1;
    }
    friend bool operator==(const String & st1, const String &st2) {
        return strcmp(st1.str, st2.str) == 0;
    }
    static int HowMany() { return num_strings; }
};

void testMyString();

#endif /* String_hpp */
