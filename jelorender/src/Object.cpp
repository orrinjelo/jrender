#include "Object.h"

Object::Object( 
    double_1darray position,
    double_1darray ambient,
    double_1darray diffuse,
    double_1darray specular,
    double         shininess,
    double         reflection
) : position_(position), ambient_(ambient), diffuse_(diffuse),
 specular_(specular), shininess_(shininess), reflection_(reflection) 
{}

Object::Object( 
    double position[3],
    double ambient[3],
    double diffuse[3],
    double specular[3],
    double shininess,
    double reflection
) {
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
    shininess_ = shininess;
    reflection_ = reflection;
}

Object::~Object() {}

double_1darray Object::getPosition() {
    return position_;
}

void Object::setPosition(double_1darray x) {
    position_ = x;
}

double_1darray Object::getAmbient() {
    return ambient_;
}

void Object::setAmbient(double_1darray x) {
    ambient_ = x;
}

double_1darray Object::getDiffuse() {
    return diffuse_;
}

void Object::setDiffuse(double_1darray x) {
    diffuse_ = x;
}

double_1darray Object::getSpecular() {
    return specular_;
}

void Object::setSpecular(double_1darray x) {
    specular_ = x;
}

double Object::getShininess() {
    return shininess_;
}

void Object::setShininess(double x) {
    shininess_ = x;
}

double Object::getReflection() {
    return reflection_;
}

void Object::setReflection(double x) {
    reflection_ = x;
}

std::pair<bool, double> Object::intersect( double_1darray origin, double_1darray destination ) {
    return std::pair<bool, double>(false, 0.0);
}