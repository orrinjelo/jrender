#pragma once

#include <iostream>
#include <memory>
#include "tnt_types.h"

class Light {
public:
    Light() = delete;
    Light( 
        double_1darray position,
        double_1darray ambient,
        double_1darray diffuse,
        double_1darray specular
    );

    Light( 
        double position[3],
        double ambient[3],
        double diffuse[3],
        double specular[3]
    );

    // TODO: make setters for double[3]

    double_1darray getPosition();
    void setPosition(double_1darray x);

    double_1darray getAmbient();
    void setAmbient(double_1darray x);

    double_1darray getDiffuse();
    void setDiffuse(double_1darray x);

    double_1darray getSpecular();
    void setSpecular(double_1darray x);

    friend std::ostream& operator<<(std::ostream& os, const Light& l);

private:
    double_1darray position_;
    double_1darray ambient_;
    double_1darray diffuse_;
    double_1darray specular_;
};

typedef std::shared_ptr<Light> light_ptr;