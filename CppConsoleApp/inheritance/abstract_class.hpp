//
//  abstract_class.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#ifndef abstract_class_hpp
#define abstract_class_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class BaseAcct {
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    BaseAcct(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    double Balance() const { return balance; }
    /* =0 结尾的函数称作“纯虚函数”，包含纯虚函数的类即为抽象类 */
    virtual void Withdraw(double amt) = 0;
    virtual void ViewAcct() const = 0;
    virtual ~BaseAcct(){}
};

#endif /* abstract_class_hpp */
