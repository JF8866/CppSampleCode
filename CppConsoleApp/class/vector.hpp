//
//  vector.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>
#include <iostream>

namespace VECTOR {

class Vector {
public:
    enum Mode{RECT, POL};
private:
    double x;
    double y;
    double mag;//length of vector
    double ang;//direction of vector in degrees
    Mode mode;
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();
public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const {return x;}
    double yval() const {return y;}
    double magval() const {return mag;}
    double angval() const {return ang;}
    void polar_mode();
    void rect_mode();
    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const;
    Vector operator-() const;//重载负号运算
    Vector operator*(double n) const;
    friend Vector operator*(double n, const Vector & a);
    friend std::ostream & operator<<(std::ostream & os, const Vector & v);
};

void testVector();

}


#endif /* vector_hpp */
