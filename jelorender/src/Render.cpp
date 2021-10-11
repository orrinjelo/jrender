#include <vector>
#include <limits>
#include "Render.h"
#include "tnt_ops.h"

#define MAX_DEPTH 1

Render::Render(
    obj_vector objects,
    camera_ptr camera,
    screen_ptr screen,
    light_ptr  light
) : objects_(objects), camera_(camera), screen_(screen), light_(light) 
{}

std::pair<obj_ptr, double> 
Render::nearestIntersectedObject(
    double_1darray rayOrigin,
    double_1darray rayDirection
) {
    std::vector<std::pair<bool, double>> distances;
    for (auto &obj : objects_) {
        distances.push_back(obj->intersect(rayOrigin, rayDirection));
    }
    obj_ptr nearestObject = nullptr;
    double minDistance = std::numeric_limits<double>::infinity();
    for (unsigned int i=0; i<distances.size(); ++i) {
        if (distances[i].first && distances[i].second < minDistance) {
            minDistance = distances[i].second;
            nearestObject = objects_[i];
        }
    }
    return std::pair<obj_ptr, double>(nearestObject, minDistance);
}

void Render::generate(std::string outputFilename) {
    const int width = screen_->getWidth();
    const int height = screen_->getHeight();
    png::image< png::rgb_pixel > image(width, height);
    double y = screen_->getTop();
    double dy = (screen_->getTop() - screen_->getBottom()) / (screen_->getHeight()-1);
    double dx = (screen_->getRight() - screen_->getLeft()) / (screen_->getWidth()-1);
    int j = 0, i = 0;
    for (; y > screen_->getBottom(); y -= dy) {
        double x = screen_->getLeft();
        j = 0;
        for (; x < screen_->getRight(); x += dx) {
            // Screen is on origin
            double_1darray pixel(3, 0.0);
            pixel[0] = x; pixel[1] = y;

            double_1darray origin = camera_->getCenter().copy();
            auto direction = normalizeVector(pixel - origin);


            double_1darray color(3, 0.0);
            double reflection = 1.0;

            for (int k=0; k<MAX_DEPTH; ++k) {
                // Check for intersections
                auto nearest = nearestIntersectedObject(origin.copy(), direction.copy());
                auto nearestObject = nearest.first;
                auto minDistance = nearest.second;
                if (nearestObject == nullptr) {
                    break;
                }
                auto intersection = origin + (double_1darray(3,minDistance)*direction);
                auto normalToSurface = normalizeVector(intersection - nearestObject->getPosition());
                auto shiftedPoint = intersection + double_1darray(3,1e-5) * normalToSurface;
                auto intersectionToLight = normalizeVector(light_->getPosition() - shiftedPoint);

                auto nearest2 = nearestIntersectedObject(shiftedPoint, intersectionToLight);
                minDistance = nearest2.second;
                auto intersectionToLightDistance = l2Norm(light_->getPosition() - intersection);
                bool isShadowed = minDistance < intersectionToLightDistance;

                if (isShadowed) break;

                double_1darray illumination(3, 0.0);

                // Ambient
                illumination += nearestObject->getAmbient()*light_->getAmbient();

                // Diffuse * np.dot(intersection_to_light, normal_to_surface)
                illumination += nearestObject->getDiffuse()*light_->getDiffuse() * double_1darray(3, dotProduct(intersectionToLight, normalToSurface));

                // Specular * np.dot(normal_to_surface, H) ** (nearest_object['shininess'] / 4)
                auto intersectionToCamera = normalizeVector(camera_->getCenter() - intersection);
                auto H = normalizeVector(intersectionToLight - intersectionToCamera);
                double specularD = std::pow( dotProduct(normalToSurface, H), nearestObject->getShininess()/4.0);
                illumination += 
                    nearestObject->getSpecular()*light_->getSpecular() 
                    * double_1darray(3, specularD);

                // Reflection
                color += double_1darray(3, reflection)*illumination;
                reflection *= nearestObject->getReflection();

                origin = shiftedPoint.copy();
                direction = reflectVector(direction, normalToSurface);
            }
            double r = std::max(std::min(color[0], 1.0), 0.0) * 256.0;
            double g = std::max(std::min(color[1], 1.0), 0.0) * 256.0;
            double b = std::max(std::min(color[2], 1.0), 0.0) * 256.0;

            image[i][j] = png::rgb_pixel(r,g,b);

            ++j;
            if ((uint32_t)j >= screen_->getWidth()) break;
        }
        ++i;
        if ((uint32_t)i >= screen_->getHeight()) break;
    }
    image.write(outputFilename);
}


obj_vector Render::getObjects() { return objects_; }
camera_ptr Render::getCamera() { return camera_; }
screen_ptr Render::getScreen() { return screen_; }
light_ptr  Render::getLight() { return light_; }
