#pragma once

#include <png++/png.hpp>
#include <utility>
#include "Object.h"
#include "Camera.h"
#include "Screen.h"
#include "Light.h"

class Render {
public:
    Render(
        obj_vector& objects,
        Camera&     camera,
        Screen&     screen,
        Light&      light
    );

    std::pair<Object*, double> nearestIntersectedObject(
        double_1darray rayOrigin,
        double_1darray rayDirection
    );

    void generate(std::string outputFilename);

private:
    obj_vector& objects_;
        Camera& camera_;
        Screen& screen_;
        Light&  light_;
};