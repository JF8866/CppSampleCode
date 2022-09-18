//
//  time.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#ifndef time_hpp
#define time_hpp

#include <stdio.h>
#include <iostream>

class Time{
private:
    int hours;
    int minutes;
    
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHour(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator*(double m) const;// 该方法只适用于 time * 1.25
    //友元函数虽然在类声明中，但不是类的函数，不能使用类对象调用，不过函数内部可以访问类的私有成员
    friend Time operator*(double m, const Time & t);// 该方法适用于 1.25 * time
    void Show() const;
    //使用友元函数实现 cout << time，功能与 Show 方法一样
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

void testOperatorOverload();

#endif /* time_hpp */
