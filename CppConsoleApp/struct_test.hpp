//
//  struct_test.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/13.
//

#ifndef struct_test_hpp
#define struct_test_hpp

#include <stdio.h>
#include <iostream>

//定义 struct / union / enum 时可以没有名字

struct ble_device {
    int rssi : 8;// 占用8个bit位
    int : 7;//使用没有名字的字段来提供位间距，即保留的位
    bool isConnected : 1;
};


union one4all {
    int int_val;
    long long_val;
    double double_val;
};


enum CharacteristicWriteType {
    WriteTypeWithResponse,
    WriteTypeWithoutResponse
};

//显式指定枚举的整型值
enum CharacteristicProperty {
    CharacteristicPropertyRead = 0x02,
    CharacteristicPropertyWriteNoReponse = 0x04,
    CharacteristicPropertyWrite = 0x08,
    CharacteristicPropertyNotify = 0x10,
    CharacteristicPropertyIndicate = 0x20,
};

// enum class 可以使用限定名，如 JColor::Red
//可以指定枚举的底层类型，如 short
enum class JColor : short  {
    Red, Green, Blue
};

void testStruct();

#endif /* struct_test_hpp */
