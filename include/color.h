#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using std::cout;
using std::endl;

class Color {
public:
    Color(float r, float g, float b, float a=1) 
        : r_(r), g_(g), b_(b), a_(a) 
    {}

    void print() {
        cout << "color [r,g,b,a] = [" << r_ << "," << g_ << "," << b_ << "," << a_ << "]" << endl;
    }

//protected:
    float r_, g_, b_, a_;
};

#endif // COLOR_H
