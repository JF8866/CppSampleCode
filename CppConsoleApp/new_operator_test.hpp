//
//  new_operator_test.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/21.
//

#ifndef new_operator_test_hpp
#define new_operator_test_hpp

#include <stdio.h>
#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;

struct Xyz {
    double x;
    double y;
    double z;
};

using namespace std;

void testNewOperator();

#endif /* new_operator_test_hpp */
