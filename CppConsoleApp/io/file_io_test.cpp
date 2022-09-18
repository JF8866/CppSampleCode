//
//  file_io_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/14.
//

#include "file_io_test.hpp"
#include <iostream>
#include <fstream>
#include <sstream> //字符串格式化

using namespace std;

void tempFileNames() {
    char temp_name[L_tmpnam] = {'\0'};
    for (int i = 0; i < 10; i++) {
        tmpnam(temp_name);
        cout << temp_name << endl;
    }
    
    ostringstream str_stream;
    str_stream << "255 = 0x" << hex << 255;
    cout << str_stream.str() << endl;
    
    
    string str = "1 2 3";
    istringstream str_in_stream(str);
    int n;
    while (str_in_stream >> n) {
        cout << n << endl;
    }
}

void testFileIO() {
    double a_price = 13500;
    double d_price = 0.913 * a_price;
    
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: Flitz Perky" << endl;
    cout << "Year: 2009" << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;
    
    ofstream outFile;
    outFile.open("carinfo.txt");//默认存储在用户目录 /Users/jiajiefei/carinfo.txt
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: Flitz Perky" << endl;
    outFile << "Year: 2009" << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;
    outFile.close();
    
    cout << "开始读取文件..." << endl;
    
    ifstream inFile;
    inFile.open("carinfo.txt");
    if(inFile.is_open()) {
        char line[100];
        while (inFile.getline(line, 100)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "打开文件失败！" << endl;
    }
}
