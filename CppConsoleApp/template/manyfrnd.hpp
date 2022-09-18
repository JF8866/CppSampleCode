//
//  manyfrnd.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#ifndef manyfrnd_hpp
#define manyfrnd_hpp

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;


//非约束模版友元函数

template<typename T>
class ManyFriend {
private:
    T item;
public:
    ManyFriend(const T & i) : item(i) {}
    template <typename C, typename D> friend void show2(C &, D &);
};

template <typename C, typename D> void show2(C & c, D & d) {
    cout << c.item << ", " << d.item << endl;
}

void testManyfrnd();

#endif /* manyfrnd_hpp */
