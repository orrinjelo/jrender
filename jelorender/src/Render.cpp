#include <vector>
#include <limits>
#include "Render.h"

Render::Render(
    obj_vector& objects,
    Camera&     camera,
    Screen&     screen,
    Light&      light
) : objects_(objects), camera_(camera), screen_(screen), light_(light) 
{}

std::pair<Object*, double> 
Render::nearestIntersectedObject(
    double_1darray rayOrigin,
    double_1darray rayDirection
) {
    std::vector<std::pair<bool, double>> distances;
    for (auto &obj : objects_) {
        distances.push_back(obj->intersect(rayOrigin, rayDirection));
    }
    Object* nearestObject = nullptr;
    double minDistance = std::numeric_limits<double>::infinity();
    for (unsigned int i=0; i<distances.size(); ++i) {
        if (distances[i].first && distances[i].second < minDistance) {
            minDistance = distances[i].second;
            nearestObject = objects_[i];
        }
    }
    return std::pair<Object*, double>(nearestObject, minDistance);
}

void Render::generate(std::string outputFilename) {

}
