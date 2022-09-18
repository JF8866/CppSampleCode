//
//  tmp2tmp.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#ifndef tmp2tmp_hpp
#define tmp2tmp_hpp

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

template<typename TT>
class HasFriendT {
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i) : item(i) {
        ct++;
    }
    ~HasFriendT() {
        ct--;
    }
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> &);
};

template<typename T>
int HasFriendT<T>::ct = 0;

//模版友元函数定义
template <typename T>
void counts() {
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template<typename T>
void report(T & hf) {
    cout << hf.item << endl;
}

void testTmp2tmp();
#endif /* tmp2tmp_hpp */
