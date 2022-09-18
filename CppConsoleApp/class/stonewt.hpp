//
//  stonewt.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#ifndef stonewt_hpp
#define stonewt_hpp

#include <stdio.h>

class Stonewt {
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;//fractional pounds
    double pounds;//entire weight in pounds
public:
    /* explicit */Stonewt(double lbs);//只有一个参数的构造函数，可以使用 explicit 关键字禁止自动转换
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    explicit operator double() const;//转换函数必须是类方法，不能指定返回类型，不能有参数
    operator int() const;
};

void testStonewt();

#endif /* stonewt_hpp */
