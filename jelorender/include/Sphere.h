#pragma once

#include <utility>
#include "Object.h"
#include "tnt_types.h"

class Sphere : public Object {
public:
    Sphere() = delete;
    Sphere( 
        double_1darray position,
        double_1darray ambient,
        double_1darray diffuse,
        double_1darray specular,
        double         shininess,
        double         reflection,
        double         radius
    );

    Sphere( 
        double position[3],
        double ambient[3],
        double diffuse[3],
        double specular[3],
        double shininess,
        double reflection,
        double radius
    );
    ~Sphere();

    // TODO: make setters for double[3]

    double getRadius();
    void setRadius(double x);

    std::pair<bool, double> intersect( double_1darray origin, double_1darray destination );

private:
    double radius_;
};