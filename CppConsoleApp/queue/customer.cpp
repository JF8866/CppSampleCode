//
//  customer.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/3.
//

#include "customer.hpp"
#include <cstdlib>

void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
