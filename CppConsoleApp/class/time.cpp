//
//  time.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#include "time.hpp"

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHour(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

//这里返回 Time 而不是 Time 引用，是因为对象是在函数内部创建的，在函数结束时将被删除
Time Time::operator+(const Time & t) const {
//    t.Show();
    int h = hours + t.hours;
    int m = minutes + t.minutes;
    h += m / 60;
    m %= 60;
    return Time(h, m);
}

Time Time::operator*(double m) const {
    Time result;
    long totalminutes = hours * m * 60 + minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}


Time operator*(double m, const Time & t) {
    Time result;
    //非成员函数可以访问类的私有成员 hours minutes
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

void Time::Show() const {
    std::cout << hours << " hours, " << minutes << " minutes\n";
}

std::ostream & operator<<(std::ostream & os, const Time & t) {
    os << t.hours << " hours, " << t.minutes << " minutes\n";
    return os;
}

void testOperatorOverload() {
    using std::cout;
    using std::endl;
    
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    
    cout << "planning time = ";
    planning.Show();
    
    cout << "coding time = ";
    coding.Show();
    
    cout << "fixing time = ";
    fixing.Show();
    
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    
    Time morefixing(3, 28);
    cout << "morefixing time = ";
    morefixing.Show();
    
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    cout << total;
}
