#pragma once

#include "tnt_types.h"

class Camera {
public:
    Camera();
    Camera( double_1darray center );
    Camera( double center[3] );
    Camera( double centerX, double centerY, double centerZ );

    // TODO: make setters for double[3]

    double_1darray getCenter();
    void           setCenter( double_1darray c );

private:
    double_1darray center_;
};