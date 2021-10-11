#include "Light.h"
#include "tnt_ops.h"

Light::Light( double_1darray position, double_1darray ambient, 
    double_1darray diffuse, double_1darray specular ) : position_(position),
    ambient_(ambient), diffuse_(diffuse), specular_(specular) {}

Light::Light( double position[3], double ambient[3], 
    double diffuse[3], double specular[3] ) {
    position_ = double_1darray(3, 0.0);
    position_[0] = position[0];
    position_[1] = position[1];
    position_[2] = position[2];
    ambient_ = double_1darray(3, 0.0);
    ambient_[0] = ambient[0];
    ambient_[1] = ambient[1];
    ambient_[2] = ambient[2];
    diffuse_ = double_1darray(3, 0.0);
    diffuse_[0] = diffuse[0];
    diffuse_[1] = diffuse[1];
    diffuse_[2] = diffuse[2];
    specular_ = double_1darray(3, 0.0);
    specular_[0] = specular[0];
    specular_[1] = specular[1];
    specular_[2] = specular[2];
}

double_1darray Light::getPosition() {
    return position_;
}


void Light::setPosition(double_1darray x) {
    position_ = x;
}


double_1darray Light::getAmbient() {
    return ambient_;
}


void Light::setAmbient(double_1darray x) {
    ambient_ = x;
}


double_1darray Light::getDiffuse() {
    return diffuse_;
}


void Light::setDiffuse(double_1darray x) {
    diffuse_ = x;
}


double_1darray Light::getSpecular() {
    return specular_;
}


void Light::setSpecular(double_1darray x) {
    specular_ = x;
}

std::ostream& operator<<(std::ostream& os, const Light& l) {
    os << "position: " << format_d1arr(l.position_) << std::endl;
    os << "ambient: " << format_d1arr(l.ambient_) << std::endl;
    os << "diffuse: " << format_d1arr(l.diffuse_) << std::endl;
    os << "specular: " << format_d1arr(l.specular_) << std::endl;
    return os;
}
