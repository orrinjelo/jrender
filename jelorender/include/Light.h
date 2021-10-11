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
    
    inline bool operator==(const Light& rhs) {
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
        specular_[2] == rhs.specular_[2];
    }

private:
    double_1darray position_;
    double_1darray ambient_;
    double_1darray diffuse_;
    double_1darray specular_;
};

typedef std::shared_ptr<Light> light_ptr;