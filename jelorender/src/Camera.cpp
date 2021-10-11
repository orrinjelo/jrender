#include "Camera.h"

using namespace TNT;

Camera::Camera() : center_(0.0) {}
Camera::Camera( double_1darray center ) : center_(center) {}

Camera::Camera( double center[3] ) {
    center_ = double_1darray(3, center);
}

Camera::Camera( double centerX, double centerY, double centerZ ) {
    center_ = double_1darray(3, 0.0);
    center_[0] = centerX;
    center_[1] = centerY;
    center_[2] = centerZ;
}


double_1darray Camera::getCenter() {
    return center_;
}


void Camera::setCenter( double_1darray c ) {
    center_ = c;
}

std::ostream& operator<<(std::ostream& os, const Camera& c) {
    os << c.center_ << std::endl;
    return os;
}
