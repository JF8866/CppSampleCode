//
//  dma.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#include "dma.hpp"
#include <cstring>

BaseDMA::BaseDMA(const char * l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

BaseDMA::BaseDMA(const BaseDMA & rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

BaseDMA::~BaseDMA() {
    delete [] label;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs) {
    if(this == &rs) return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs) {
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}


// LacksDMA methods
LacksDMA::LacksDMA(const char * c, const char * l, int r) : BaseDMA(l, r) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

LacksDMA::LacksDMA(const char * c, const BaseDMA & rs) : BaseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & ls) {
    os << (const BaseDMA &) ls;//使用基类的友元函数
    os << "Color: " << ls.color << std::endl;
    return os;
}


// HasDMA methods
HasDMA::HasDMA(const char * s, const char * l, int r) : BaseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

HasDMA::HasDMA(const char * s, const BaseDMA & rs) : BaseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

HasDMA::HasDMA(const HasDMA & hs) : BaseDMA(hs) {
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

HasDMA::~HasDMA() {
    delete [] style;
}

HasDMA & HasDMA::operator=(const HasDMA & hs) {
    if(this == &hs) return *this;
    BaseDMA::operator=(hs);//调用基类的赋值函数处理基类的动态内存数据
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & hs) {
    os << (const BaseDMA &) hs;//使用基类的友元函数
    os << "Style: " << hs.style << std::endl;
    return os;
}


void testDMA() {
    using std::cout;
    using std::endl;
    
    BaseDMA shirt("Portabelly", 8);
    LacksDMA balloon("red", "Blimpo", 4);
    HasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying BaseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying LacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying HasDMA object:\n";
    cout << map << endl;
    LacksDMA balloon2(balloon);
    cout << "Result of LacksDMA copy:\n";
    cout << balloon2 << endl;
    HasDMA map2;
    map2 = map;
    cout << "Result of HasDMA assignment:\n";
    cout << map2 << endl;
}
