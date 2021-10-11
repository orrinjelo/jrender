#pragma once

#include <memory>
#include <cstdint>
#include <iostream>

class Screen {
public:
    Screen() = delete;
    Screen( uint32_t height, uint32_t width );

    uint32_t  getHeight();
    void      setHeight( uint32_t );

    uint32_t  getWidth();
    void      setWidth( uint32_t );

    double  getRatio();
    double  getLeft();
    double  getRight();
    double  getTop();
    double  getBottom();

    friend std::ostream& operator<<(std::ostream& os, const Screen& s);

private:

    void calculateEdges();

    uint32_t height_;
    uint32_t width_;
    double   ratio_;
    double   left_;
    double   right_;
    double   top_;
    double   bottom_;
};

typedef std::shared_ptr<Screen> screen_ptr;