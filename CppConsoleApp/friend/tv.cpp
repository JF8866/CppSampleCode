//
//  tv.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "tv.hpp"
#include <iostream>

bool Tv::volup() {
    if(volume < MaxVal) {
        volume++;
        return true;
    }
    return false;
}

bool Tv::voldown() {
    if(volume > MinVal) {
        volume--;
        return true;
    }
    return false;
}

void Tv::chanup() {
    if(channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown() {
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const {
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

void testTV() {
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    
    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    
    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();
}
