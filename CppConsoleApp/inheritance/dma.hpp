//
//  dma.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#ifndef dma_hpp
#define dma_hpp

#include <stdio.h>
#include <iostream>

//继承和动态内存分配

class BaseDMA {
private:
    char * label;
    int rating;
    
public:
    BaseDMA(const char * l = "null", int r = 0);
    BaseDMA(const BaseDMA & rs);
    virtual ~BaseDMA();
    BaseDMA & operator=(const BaseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const BaseDMA & rs);
};



//派生类没有使用 new 动态分配内存
class LacksDMA : public BaseDMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    LacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    LacksDMA(const char * c, const BaseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const LacksDMA & ls);
};


//派生类使用 new 动态分配内存
class HasDMA : public BaseDMA {
private:
    char * style;
public:
    HasDMA(const char * s = "none", const char * l = "null", int r = 0);
    HasDMA(const char * s, const BaseDMA & rs);
    HasDMA(const HasDMA & hs);//复制构造函数
    ~HasDMA();//析构函数
    HasDMA & operator=(const HasDMA & hs);//赋值运算符
    friend std::ostream & operator<<(std::ostream & os, const HasDMA & hs);
};

void testDMA();

#endif /* dma_hpp */
