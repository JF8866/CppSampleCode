//
//  namespace_test.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/21.
//

#ifndef namespace_test_hpp
#define namespace_test_hpp

#include <stdio.h>
#include <string>

namespace pers {
    struct Person {
        std::string fname;
        std::string lname;
    };
    void getPersion(Person &);
    void showPerson(const Person &);
}

namespace debts {
    using namespace pers;
    struct Debt {
        Person name;
        double amount;
    };

    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt [], int);
}

void testNamespace();
void other(void);
void anther(void);

#endif /* namespace_test_hpp */
