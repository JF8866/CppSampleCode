//
//  struct_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/13.
//

#include "struct_test.hpp"

using namespace std;

void testStruct() {
    ble_device device = { -60, true };
    cout << "rssi=" << device.rssi
        << ", isConnected=" << device.isConnected
        << endl;
    
    //使用 new 初始化结构体
    ble_device *ptr_device = new ble_device;
    ptr_device->rssi = -70;
    (*ptr_device).isConnected = false;
    cout << "rssi=" << ptr_device->rssi
        << ", isConnected=" << ptr_device->isConnected
        << endl;
    delete ptr_device;
    
    //枚举
    CharacteristicWriteType t = WriteTypeWithResponse;
    t = CharacteristicWriteType(0);
    //算术表达式中枚举可以自动转换成int，但是int不能自动转换成枚举
    int sum = WriteTypeWithResponse + WriteTypeWithoutResponse;
    cout << "WriteTypeWithResponse + WriteTypeWithoutResponse = " << sum << endl;
    
    cout << "JColor::Red = " << (int)JColor::Red << endl;
}
