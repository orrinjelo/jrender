#pragma once

#include <iostream>
#include <memory>
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

    friend std::ostream& operator<<(std::ostream& os, const Camera& c);

private:
    double_1darray center_;
};

typedef std::shared_ptr<Camera> camera_ptr;