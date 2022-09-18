//
//  manyfrnd.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "manyfrnd.hpp"

void testManyfrnd() {
    ManyFriend<int> hfi11(10);
    ManyFriend<int> hfi22(20);
    ManyFriend<double> hfdbx(10.5);
    cout << "hfi11, hfi22: ";
    show2(hfi11, hfi22);
    cout << "hfdbx, hfi22: ";
    show2(hfdbx, hfi22);
}
