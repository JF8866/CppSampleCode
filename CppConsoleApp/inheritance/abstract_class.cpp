//
//  abstract_class.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#include "abstract_class.hpp"

using std::cout;

BaseAcct::BaseAcct(const std::string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void BaseAcct::Deposit(double amt) {
    if(amt < 0) {
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

void BaseAcct::Withdraw(double amt) {
    balance -= amt;
}

BaseAcct::Formatting BaseAcct::SetFormat() const {
    // set up ###.## format
    Formatting f;
    f.flag = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void BaseAcct::Restore(Formatting & f) const {
    cout.setf(f.flag, std::ios_base::floatfield);
    cout.precision(f.pr);
}
