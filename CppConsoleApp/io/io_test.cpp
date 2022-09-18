//
//  io_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/12.
//

#include "io_test.hpp"

void coutSample() {
    cout << hex;//16进制输出
//    cout.setf(ios_base::showbase);//显示0x，但是只能显示 0xa 显示不成 0x0a
    cout.setf(ios_base::uppercase);//对于16进制输出，使用大写字母
//    cout.setf(ios_base::showpos);//正数前面显示加号
    //效果跟 << hex 一样，第一个参数是要设置的标志位，第二个参数是要清除的位域
    cout.setf(ios_base::hex, ios_base::basefield);
    cout.fill('0');//左侧填充0
    cout.width(2);//宽度仅对紧跟其后的输出有效
    cout << 10 << endl;
    
    double d = 3.141592653;
    cout.precision(3);//有效位数（包含整数部分和小数部分）
    //加上下面这一行后，上一行设置的精度将只包含小树位数
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << d << endl;
    
    
    double a = 1.0;
    cout.setf(ios_base::showpoint);//前面设置了精度为3（默认是6），所以下面一行输出 1.00
    cout << a << endl;
    
    cout.setf(ios_base::boolalpha);//布尔值输出为 true false，默认输出 1 0
    cout << true << endl;
    
    cout.unsetf(ios_base::floatfield);//恢复默认
}

void coutSample2() {
    cout << fixed << right;
    cout << setw(6) << "N" << setw(14) << "square root" << setw(15) << "fourth root\n";
    double root;
    for (int n = 10; n <= 100; n += 10) {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n << setfill(' ')
              << setw(12) <<setprecision(3) << root
              << setw(14) << setprecision(4) << sqrt(root)
              << endl;
    }
}


void cinException() {
    //have failbit cause an exception to be thrown
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";
    int sum = 0;
    int input;
    try {
        while (cin >> input) {
            sum += input;
        }
    } catch (ios_base::failure & bf) {
        cout << bf.what() << endl;
        cout << "O! the horror!\n";
    }
    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
}

void testIO() {
//    coutSample();
//    coutSample2();
    cinException();
}
