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

    obj_vector getObjects();
    camera_ptr getCamera();
    screen_ptr getScreen();
    light_ptr  getLight();

    inline bool operator==(const Render& rhs) {
        if (objects_.size() != rhs.objects_.size())
            return false;
        bool affirm = true;
        for (unsigned int i=0; i<objects_.size(); ++i) {
            affirm &= (*(objects_[i]) == *(rhs.objects_[i]));
        }
        if (!affirm)
            return false;
        if (!(*camera_ == *rhs.camera_))
            return false;
        if (!(*screen_ == *rhs.screen_))
            return false;
        return *light_ == *rhs.light_;
    }

private:
    obj_vector objects_;
    camera_ptr camera_;
    screen_ptr screen_;
    light_ptr  light_;
};