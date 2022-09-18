//
//  string_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/13.
//

#include "string_test.hpp"
#include <string>
#include <iostream>

using namespace std;

void stringStyles();

void stringInpput() {
    //C风格字符串
    char info[100];
    cin >> info;//read a word
    cin.getline(info, 100);//读取一行，丢弃换行符
    cin.get(info, 100);//读取一行，保留换行符
    
    //string类
    string stuff;
    cin >> stuff;//read a word
    getline(cin, stuff);//读取一行，丢弃换行符
}


void testString() {
    stringStyles();
    
    //string构造函数
    string s = "Hello";
    cout << string(50, '*') << endl;//创建包含10个星号的字符串
    cout << string("Hello", 3) << endl;//截取前n个字符
    cout << string(s, 3) << endl;//截取从第4个字符开始到结尾的字符串
    cout << string(s, 3, 1) << endl;//从第4个字符开始取1个字符
    
    string one("Lottery Winner!");
    one[0] = 'P';
    cout << one << endl;
    char alls[] = "All's well that ends well";
    cout << string(alls, 20) << endl;
    cout << string(alls + 6, alls + 10) << endl;//well
    cout << string(&one[8], &one[14]) << endl;//Winner
}

void stringStyles() {
    char c_str[] = "C string";
    wchar_t title[] = L"Chief Astrogator";
    char16_t name[] = u"Felonia Ripova";
    char32_t car[] = U"Humber Supper Snipe";
    string utf8Str = u8"中国";
    //原始字符串使用 "( 和 )" 作为分界符，引号和圆括号之间之间加入相同的字符即可在字符串中包含 "( 和 )"
    string rawStr1 = R"(raw string\n)";
    string rawStr2 = R"+*("(raw string\n)")+*";
    
    cout << c_str << endl;
    wcout << title << endl;
    cout << name << endl;
    cout << car << endl;
    cout << utf8Str << endl;
    cout << rawStr1 << endl;
    cout << rawStr2 << endl;
}
