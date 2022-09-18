//
//  String.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/30.
//

#include "String.hpp"
#include <cstdlib>
#include <ctime>

const int ArSize = 10;
const int MaxLen = 81;

//初始化类的静态成员
int String::num_strings = 0;

String::String(const char * s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & sb) {
    num_strings++;
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
}

String::~String() {
    num_strings--;
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const String & st) {
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is) {
        st = temp;
    }
    while (is && is.get() != '\n') {
        continue;
    }
    return is;
}

//重载赋值运算符
String & String::operator=(const String & sb) {
    if(this == &sb) return *this;
    delete [] str;//free old string
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    return *this;
}

//这个版本的赋值运算符，可提升将C字符串赋值给 String 对象时的性能（不用创建临时变量）
String & String::operator=(const char * s) {
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator[](int i) {
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}



void testMyString() {
    using namespace std;
    
    String name;
    cout << "Hi, what's your name?\n>>";
    cin >> name;
    
    cout << name << ", please enter up to " << ArSize << " short saying <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n') {
            continue;
        }
        if(!cin || temp[0] == '\0') {
            break;
        } else {
            sayings[i] = temp;
        }
    }
    int total = i;
    if(total > 0) {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++) {
            cout << sayings[i] << "\n";
        }
        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for (i = 1; i < total; i++) {
            if(sayings[i].length() < shortest->length()) {
                shortest = &sayings[i];
            }
            if(sayings[i] < *first) {
                first = &sayings[i];
            }
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;
    } else {
        cout << "Not much to say, eh?\n";
    }
    cout << "Byte!\n";
}
