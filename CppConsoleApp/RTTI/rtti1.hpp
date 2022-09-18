//
//  rtti1.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#ifndef rtti1_hpp
#define rtti1_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

/* RTTI: Runtime Type Identification 运行时类型识别。
 C++有3个支持RTTI的元素。
 1、如果可能的话，dynamic_cast运算符将使用一个指向基类的指针来生成一个指向派生类的指针；否则，该运算符返回0——空指针。
 2、typeid运算符返回一个指出对象的类型的值。
 3、type_info结构存储了有关特定类型的信息。
 只能将RTTI用于包含虚函数的类层次机构。 */

class Grand {
private:
    int hold;
public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { cout << "I am a grand class!\n"; }
    virtual int Value() const { return hold; }
};

class Superb : public Grand {
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const { cout << "I am a superb class!!\n"; }
    virtual void Say() const {
        cout << "I hold the superb value of " << Value() << "!\n";
    }
};

class Magnificent : public Superb {
private:
    char ch;
public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const {
        cout << "I am a magnificent class!!!\n";
    }
    void Say() const {
        cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";
    }
};

void testRTTI1();

#endif /* rtti1_hpp */
