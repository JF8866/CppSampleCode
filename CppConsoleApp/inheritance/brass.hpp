//
//  brass.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#ifndef brass_hpp
#define brass_hpp

#include <stdio.h>
#include "abstract_class.hpp"
//#include <string>

class Brass : public BaseAcct {
public:
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0) : BaseAcct(s, an, bal) {}
    virtual void Withdraw(double amt);//取款
    /* virtual 标记的方法表明要在子类中重写，如果使用父类引用子类对象，调用该方法时将根据运行时的类型（而不是声明的类型）选择调用哪个类的方法 */
    virtual void ViewAcct() const;
    /* 虚析构函数可以确保正确的析构函数序列被调用，如果派生类包含一个执行某些操作的析构函数，则基类必须有一个虚析构函数，即使该析构函数不执行任何操作。 */
    virtual ~Brass();
};

class BrassPlus : public BaseAcct {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif /* brass_hpp */
