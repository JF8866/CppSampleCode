//
//  pointer_test.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/13.
//

#ifndef pointer_test_hpp
#define pointer_test_hpp

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Report {
private:
    string str;
public:
    Report(const string s) : str(s) {
        cout << "Object created!\n";
    }
    ~Report() {
        cout << "Object deleted!\n";
    }
    void comment() const {
        cout << str << endl;
    }
};

void testPointer();

#endif /* pointer_test_hpp */
