#pragma once

#include <memory>
#include "json.hpp"
#include "Light.h"
#include "Render.h"
#include "Screen.h"
#include "Sphere.h"
#include "Camera.h"

class RenderParser {
public:
    RenderParser(std::string jsonStr);
    // ~RenderParser();

    std::shared_ptr<Render> getRender();

private:
    std::shared_ptr<Render> render_;    
};