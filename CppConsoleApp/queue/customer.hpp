//
//  customer.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/3.
//

#ifndef customer_hpp
#define customer_hpp

#include <stdio.h>

class Customer {
private:
    long arrive;
    int processtime;
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

#endif /* customer_hpp */
