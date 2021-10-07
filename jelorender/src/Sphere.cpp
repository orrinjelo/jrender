#include <cmath>
#include "Sphere.h"
#include "tnt_ops.h"

Sphere::Sphere( 
    double_1darray position,
    double_1darray ambient,
    double_1darray diffuse,
    double_1darray specular,
    double         shininess,
    double         reflection,
    double         radius
) : Object(position, ambient, diffuse, specular, shininess, reflection), radius_(radius)
{}

Sphere::Sphere( 
    double position[3],
    double ambient[3],
    double diffuse[3],
    double specular[3],
    double shininess,
    double reflection,
    double radius
) : Object(position, ambient, diffuse, specular, shininess, reflection), radius_(radius)
{}

double Sphere::getRadius() {
    return radius_;
}

void Sphere::setRadius(double x) {
    radius_ = x;
}

std::pair<bool, double> Sphere::intersect( 
    double_1darray origin, 
    double_1darray destination 
) {
    double b = 2.0 * dotProduct(destination, origin - position_);
    double c = std::pow(l2Norm(origin - position_), 2) - std::pow(radius_, 2);
    double delta = std::pow(b, 2.0) - (4.0*c);
    if (delta > 0.0) {
        double t1 = (-b + std::sqrt(delta)) / 2.0;
        double t2 = (-b - std::sqrt(delta)) / 2.0;
        if (t1 > 0 and t2 > 0) {
            return std::pair<bool, double>(true, std::min(t1, t2));
        }
    }
    return std::pair<bool, double>(false, 0.0);
}
