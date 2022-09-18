//
//  stock.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/27.
//

#ifndef stock_hpp
#define stock_hpp

#include <stdio.h>
//#include <string>
#include <iostream>

class Stock {
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    //类声明中定义的函数（带有函数体，即在类声明中实现的函数）将自动成为內联函数
    void set_tot() {
        total_val = shares * share_val;
    }
public:
    //构造函数
    Stock();//默认构造函数
    //自定义构造函数
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    //析构函数
    ~Stock();
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;//const 保证函数不会修改调用对象
    double total() const {
        return total_val;
    }
    const Stock & topval(const Stock & stock) const;
};

void testClass();

#endif /* stock_hpp */
