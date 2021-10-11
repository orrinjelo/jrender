#pragma once

#include <png++/png.hpp>
#include <memory>
#include <utility>
#include "Object.h"
#include "Camera.h"
#include "Screen.h"
#include "Light.h"

class Render {
public:
    Render(
        obj_vector objects,
        camera_ptr camera,
        screen_ptr screen,
        light_ptr  light
    );

    std::pair<obj_ptr, double> nearestIntersectedObject(
        double_1darray rayOrigin,
        double_1darray rayDirection
    );

    void generate(std::string outputFilename);

private:
    obj_vector objects_;
    camera_ptr camera_;
    screen_ptr screen_;
    light_ptr  light_;
};