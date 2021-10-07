#pragma once

#include <cstdint>

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