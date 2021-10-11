#pragma once

#include <vector>
#include <memory>
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

    virtual ~Object();

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

    virtual std::pair<bool, double> intersect( double_1darray origin, double_1darray destination );

    inline bool operator==(const Object& rhs) {
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
        reflection_ == rhs.reflection_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Object& s);

protected:
    double_1darray position_;
    double_1darray ambient_;
    double_1darray diffuse_;
    double_1darray specular_;
    double         shininess_;
    double         reflection_;
};


typedef std::shared_ptr<Object> obj_ptr;
typedef std::vector<obj_ptr> obj_vector;