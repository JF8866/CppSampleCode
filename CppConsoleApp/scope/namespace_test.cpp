//
//  namespace_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/21.
//

#include "namespace_test.hpp"
#include <iostream>

namespace pers {
    using std::cout;
    using std::cin;

    void getPerson(Person &rp) {
        cout << "Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }

    void showPerson(const Person &rp) {
        cout << rp.lname << ", " << rp.fname;
    }
}

namespace debts {
    void getDebt(Debt &rd) {
        getPerson(rd.name);
        cout << "Enter debt: ";
        cin >> rd.amount;
    }

    void showDebt(const Debt &rd) {
        showPerson(rd.name);
        cout << ": $" << rd.amount << std::endl;
    }

    double sumDebts(const Debt ar[], int n) {
        double total = 0.0;
        for (int i = 0; i < n; i++) {
            total += ar[i].amount;
        }
        return total;
    }
}

void testNamespace() {
    using debts::Debt;
    using debts::showDebt;
    Debt golf = {{"Benny", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    anther();
}

void other(void) {
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for (i = 0; i < 3; i++) {
        getDebt(zippy[i]);
    }
    for (i = 0; i < 3; i++) {
        showDebt(zippy[i]);
    }
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
}

void anther(void) {
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}
