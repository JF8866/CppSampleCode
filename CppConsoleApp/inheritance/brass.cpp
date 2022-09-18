//
//  brass.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#include "brass.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;


Brass::~Brass() {
    
}


void Brass::Withdraw(double amt) {
    if(amt < 0) {
        cout << "Withdrawal amount must be positive; withdrawal canceled.\n";
    } else if (amt <= Balance()) {
        BaseAcct::Withdraw(amt);
    } else {
        cout << "Withddrawal amount of $" << amt << " exceeds your balance.\nWithdrawal canceled.\n";
    }
}


void Brass::ViewAcct() const {
    // set up ###.## format
    Formatting f = SetFormat();
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : BaseAcct(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : BaseAcct(ba) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate  << "%" << endl;
    Restore(f);
}

void BrassPlus::Withdraw(double amt) {
    Formatting f = SetFormat();
    double bal = Balance();
    if(amt <= bal) {
        BaseAcct::Withdraw(amt);
    } else if(amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        BaseAcct::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    Restore(f);
}
