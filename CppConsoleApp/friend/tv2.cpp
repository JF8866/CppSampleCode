//
//  tv2.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "tv2.hpp"
#include <iostream>

bool Tv2::volup() {
    if(volume < MaxVal) {
        volume++;
        return true;
    }
    return false;
}

bool Tv2::voldown() {
    if(volume > MinVal) {
        volume--;
        return true;
    }
    return false;
}

void Tv2::chanup() {
    if(channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv2::chandown() {
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv2::settings() const {
    using std::cout;
    using std::endl;
    cout << "Tv is " << (state == Off ? "Off" : "On") << endl;
    if(state == On) {
        cout << "Volume: " << volume << endl;
        cout << "Channel: " << channel << endl;
        cout << "Mode: " << (mode == Antenna ? "Antenna" : "Cable") << endl;
        cout << "Input: " << (input == TV ? "TV" : "DVD") << endl;
    }
}
