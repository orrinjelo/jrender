#pragma once

#include "tnt_types.h"

class Object {
public:
    Object() = delete;
    Object( 
        double_1darray position,
        double_1darray ambient,
        double_1darray diffuse,
        double_1darray specular,
        double         shininess,
        double         reflection
    );

    Object( 
        double position[3],
        double ambient[3],
        double diffuse[3],
        double specular[3],
        double shininess,
        double reflection
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

    double getShininess();
    void setShininess(double x);

    double getReflection();
    void setReflection(double x);

    // virtual std::pair<bool, double> intersect( double_1darray origin, double_1darray destination );

protected:
    double_1darray position_;
    double_1darray ambient_;
    double_1darray diffuse_;
    double_1darray specular_;
    double         shininess_;
    double         reflection_;
};