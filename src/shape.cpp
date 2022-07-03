#include "shape.h"

#include <iostream>

using std::cout;
using std::endl;

NVGcontext * Shape::vg_ = nullptr;

Shape::Shape(int x, int y, Color c)
    : x_(x),
      y_(y),
      c_(c)
{
    
}

pair<int, int> Shape::position() const {
    return std::make_pair(x_, y_);
}

// Color& Shape::color()const {
//     return this->c_;
// }

void Shape::set_position(int x, int y) {
    x_ = x;
    y_ = y;
}

void Shape::print() {
    cout << "printing shape: [x,y,c] = [" << x_ << "," << y_ << "," << "...]" << endl;
    c_.print();  
}

void Shape::set_nvgContext(NVGcontext *ctx) {
   vg_ = ctx; 
}


Rectangle::Rectangle(int x, int y, int w, int h, Color c)
    : Shape(x, y, c),
      w_(w),
      h_(h)
{
    
}

pair<int, int> Rectangle::size() const {
    return std::make_pair(w_, h_);
}

void Rectangle::set_size(int w, int h) {
    w_ = w;
    h_ = h;
}

void Rectangle::render() {
    cout << "rendering rectangle" << endl;
}

void Rectangle::print() {
    cout << "printing shape: [x,y,w,h,c] = [" << x_ << "," << y_ << "," << w_ << "," << h_ << "...]" << endl;
    c_.print();  
}

Circle::Circle(int x, int y, int r, Color c)
    : Shape(x, y, c),
      r_(r)
{
    
}

int Circle::radius() const {
    return r_;
}

void Circle::set_radius(int r) {
    r_ = r;    
}

void Circle::render() {
    //cout << "rendering circle" << endl;
    nvgBeginPath(vg_);
    nvgCircle(vg_, this->x_, this->y_, this->r_);
    auto [x,y] = this->position();
    //Circle &c = *this;
    Color &c = (this->c_);
    nvgStrokeColor(vg_, nvgRGBAf(c.r_, c.g_, c.b_, c.a_));
    nvgStrokeWidth(vg_, 1.0);
    nvgStroke(vg_);
    nvgClosePath(vg_);
}

void Circle::print() {
    cout << "circle " << this->x_ << endl;

}
