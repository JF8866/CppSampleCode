//
//  vector.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#include "vector.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {

const double Rad_to_deg = 45.0 / atan(1.0);
void Vector::set_mag() {
    mag = sqrt(x * x + y * y);
}

void Vector::set_ang() {
    if(x == 0.0 && y == 0.0) {
        ang = 0.0;
    } else {
        ang = atan2(y, x);
    }
}

void Vector::set_x() {
    x = mag * cos(ang);
}

void Vector::set_y() {
    y = mag * sin(ang);
}

Vector::Vector() {
    x = y = ang = 0.0;
    mode = RECT;
}

Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if(form == RECT) {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    } else if (form == POL) {
        mag = n1;
        ang = n2 / Rad_to_deg;
        set_x();
        set_y();
    } else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
}

void Vector::reset(double n1, double n2, Mode form) {
    mode = form;
    if(form == RECT) {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    } else if (form == POL) {
        mag = n1;
        ang = n2 / Rad_to_deg;
        set_x();
        set_y();
    } else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
}

Vector::~Vector() {
    
}

void Vector::polar_mode() {
    mode = POL;
}

void Vector::rect_mode() {
    mode = RECT;
}

Vector Vector::operator+(const Vector &b) const {
    return Vector(x + b.x, y + b.y);
}

Vector Vector::operator-(const Vector &b) const {
    return Vector(x - b.x, y - b.y);
}

Vector Vector::operator*(double n) const {
    return Vector(x * n, y * n);
}

Vector Vector::operator-() const {
    return Vector(-x, -y);
}

std::ostream & operator<<(std::ostream & os, const Vector & v) {
    if(v.mode == Vector::RECT) {
        os << "(x, y) = (" << v.x << ", " << v.y << ")";
    } else if(v.mode == Vector::POL) {
        os << "(mag, ang) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
    } else {
        os << "Vector object mode is invalid";
    }
    return os;
}


void testVector() {
    //随机漫步
    using namespace std;
    using  VECTOR::Vector;
    srand(time(0));//seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if(!(cin >> dstep)) break;
        
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
}


}
