#include <boost/log/trivial.hpp>
#include <cassert>
#include "Screen.h"

Screen::Screen( uint32_t height, uint32_t width ) : height_(height), width_(width) {
    calculateEdges();
}

void Screen::calculateEdges() {
    assert(height_ != 0);
    ratio_ = static_cast<double>(width_) / height_;
    left_ = -1.0;
    right_ = 1.0;
    top_ = 1.0 / ratio_;
    bottom_ = -1.0 / ratio_;
}

uint32_t Screen::getHeight() {
    return height_;
}

void Screen::setHeight( uint32_t h ) {
    height_ = h;
    calculateEdges();
}

uint32_t Screen::getWidth() {
    return width_;
}

void Screen::setWidth( uint32_t w ) {
    width_ = w;
    calculateEdges();
}


double Screen::getRatio() {
    return ratio_;
}


double Screen::getLeft() {
    return left_;
}


double Screen::getRight() {
    return right_;
}


double Screen::getTop() {
    return top_;
}


double Screen::getBottom() {
    return bottom_;
}

std::ostream& operator<<(std::ostream& os, const Screen& s) {
    os << "width: " << s.width_ << std::endl;
    os << "height: " << s.height_ << std::endl;
    os << "ratio: " << s.ratio_ << std::endl;
    os << "left: " << s.left_ << std::endl;
    os << "right: " << s.right_ << std::endl;
    os << "top: " << s.top_ << std::endl;
    os << "bottom: " << s.bottom_ << std::endl;
    return os;
}
