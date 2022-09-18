//
//  tv2.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#ifndef tv2_hpp
#define tv2_hpp

#include <stdio.h>

/* tv.hpp 中 Remote 类的大部分方法都是直接调用 Tv 类的对应方法，实际上只需要将 set_chan() 方法作为友元(访问私 Tv 的有数据)，而要把 Remote 的 set_chan() 方法声明为 Tv 的友元，需要把 Remote 的声明放在 Tv 前面，Remote 的方法有参数是 Tv，这意味着 Tv 定义应当位于 Remote 之前，处理这种循环依赖的方式是使用前向声明（forward declaration） */

class Tv2;//forward declaration
class Remote2 {
public:
    enum State {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
private:
    int mode;
public:
    Remote2(int m = TV) : mode(m) {}
    bool volup(Tv2 & t);
    bool bvoldown(Tv2 & t);
    void onoff(Tv2 & t);
    void chanup(Tv2 & t);
    void chandown(Tv2 & t);
    void set_mode(Tv2 & t);
    void set_input(Tv2 & t);
    void set_chan(Tv2 & t, int c);//方法实现要放到 Tv2 后面
};


class Tv2 {
public:
    friend void Remote2::set_chan(Tv2 &t, int c);//把 set_chan 声明为电视类的友元
    enum State {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
    
    Tv2(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {
        state = state == On ? Off : On;
    }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {
        mode = mode == Antenna ? Cable : Antenna;
    }
    void set_input() {
        input = input == TV ? DVD : TV;
    }
    void settings() const;
    
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

inline bool Remote2::volup(Tv2 & t) { return t.volup(); }
inline bool Remote2::bvoldown(Tv2 & t) { return t.voldown(); }
inline void Remote2::onoff(Tv2 & t) { t.onoff(); }
inline void Remote2::chanup(Tv2 & t) { t.chanup(); }
inline void Remote2::chandown(Tv2 & t) { t.chandown(); }
inline void Remote2::set_chan(Tv2 & t, int c) { t.channel = c; }//Tv2的友元方法可以访问Tv2的私有数据
inline void Remote2::set_mode(Tv2 & t) { t.set_mode(); }
inline void Remote2::set_input(Tv2 & t) { t.set_input(); }


void testTV2();

#endif /* tv2_hpp */
