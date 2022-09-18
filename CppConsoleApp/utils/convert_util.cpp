//
//  convert_util.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/20.
//

#include "convert_util.hpp"
#include <iostream>
#include <string>

using namespace std;

void testConvertUtil() {
    char* str;
    for (int i = 100; i <= 200; i++) {
        str = int2str(i);
        cout << i << " <-> " << str << endl;
        delete [] str;
    }
}

char* int2str(int i) {
    char *str = new char[20];
    int integer = i;
    int len = 1;
    while (integer /= 10) {
        len++;
    }
//    cout << i << " len=" << len << endl;
    integer = i;
    for (int j = len - 1; j >= 0; j--) {
        str[j] = (integer % 10) + '0';
        integer /= 10;
    }
    str[len] = '\0';
    return str;
}
