#pragma once

#include <iostream>
#include <utility>
#include <memory>
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

    double getRadius();
    void setRadius(double x);

    std::pair<bool, double> intersect( double_1darray origin, double_1darray destination );

    inline bool operator==(const Sphere& rhs) {
        return
        position_[0] == rhs.position_[0] &&
        position_[1] == rhs.position_[1] &&
        position_[2] == rhs.position_[2] &&
        ambient_[0] == rhs.ambient_[0] &&
        ambient_[1] == rhs.ambient_[1] &&
        ambient_[2] == rhs.ambient_[2] &&
        diffuse_[0] == rhs.diffuse_[0] &&
        diffuse_[1] == rhs.diffuse_[1] &&
        diffuse_[2] == rhs.diffuse_[2] &&
        specular_[0] == rhs.specular_[0] &&
        specular_[1] == rhs.specular_[1] &&
        specular_[2] == rhs.specular_[2] &&
        shininess_ == rhs.shininess_ &&
        reflection_ == rhs.reflection_ &&
        radius_ == rhs.radius_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Sphere& s);

private:
    double radius_;
};

typedef std::shared_ptr<Sphere> sphere_ptr;