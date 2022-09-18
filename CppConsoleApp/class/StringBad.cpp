//
//  StringBad.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/29.
//

#include "StringBad.hpp"
using std::cout;

void callme1(StringBad &);
void callme2(StringBad);

//初始化类的静态成员
int StringBad::num_strings = 0;

StringBad::StringBad(const char * s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::StringBad(const StringBad & sb) {
    num_strings++;
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted, ";
    num_strings--;
    cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st) {
    os << st.str;
    return os;
}

//重载赋值运算符
StringBad & StringBad::operator=(const StringBad & sb) {
    if(this == &sb) return *this;
    delete [] str;//free old string
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    return *this;
}


void testStringBad() {
    using std::endl;
    
    cout << "Starting testStringBad().\n";
    StringBad headline1("Celety Stalks at Midnight");//芹菜在午夜悄然而至
    StringBad headline2("Lettuce Prey");//莴苣猎物
    StringBad sports("Spinach Leaves Bow1 for Dollars");//菠菜叶1美元
    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    callme1(headline1);
    cout << "headline1: " << headline1 << endl;
    callme2(headline2);//按值传递给函数，函数返回时会调用析构函数，从而将 headline2 释放
    cout << "headline2: " << headline2 << endl;
    cout << "Initialize one object to anther:\n";
    
    //下面的初始化等价于 StringBad sailor = StringBad(sports);
    //对应的初始化函数原型为 StringBad(const StringBad &);
    //当使用一个对象来初始化另一个对象时，编译器会自动生成上述构造函数（称为复制构造函数，因为它创建对象的一个副本，这种复制是浅复制，所以多个对象在析构函数中释放 new 创建的 str 时，可能释放同一块内存两次，从而引发异常）。
    StringBad sailor = sports;
    //以下3种方式也都调用了隐式构造函数 StringBad(const StringBad &)
//    StringBad sailor2 = StringBad(sports);
//    StringBad sailor3(sports);
//    StringBad *sailor4 = new StringBad(sports);
    
    cout << "sailor: " << sailor << endl;
    cout << "Assign one object to another:\n";
    StringBad knot;//调用默认构造函数
    //下面的赋值运算，涉及类的另一个隐式成员函数，赋值运算函数，跟复制构造函数一样，赋值运算函数也会创建对象的副本（也是浅复制）
    knot = headline1;//
    cout << "knot: " << knot << endl;
    cout << "Exiting testStringBad().\n";
}

void callme1(StringBad & rsb) {
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}
