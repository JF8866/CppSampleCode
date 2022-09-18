//
//  stonewt.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#include "stonewt.hpp"
#include <iostream>

Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {
    
}

void Stonewt::show_stn() const {
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const {
    std::cout << pounds << " pounds\n";
}

Stonewt::operator double() const {
    return pounds;
}

Stonewt::operator int() const {
    return int(pounds + 0.5);//四舍五入
}

void display(const Stonewt & st, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Wow! ";
        st.show_stn();
    }
}

void testStonewt() {
    //只有一个参数的构造函数，可以使用参数类型的值直接初始化类对象
    //Stonewt myCat = 19.6;
    
    //当对应的构造函数使用 explicit 禁用自动转换时，仍然可以使用强制类型转换
//    Stonewt myCat = (Stonewt)19.6;
//    myCat.show_lbs();
    
    Stonewt incognito = 275;//自动转换
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);
    display(422, 2);//422 先被转换成 double，然后转换成 Stonewt
    double thinker = wolfe;//类的 operator double() 函数起作用
    std::cout << int(taft) << std::endl;//类的 operator int() 函数起作用
}
