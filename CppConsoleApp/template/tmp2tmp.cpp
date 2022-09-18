//
//  tmp2tmp.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "tmp2tmp.hpp"

void testTmp2tmp() {
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);
    report(hfi2);
    report(hfdb);
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();
}
