#include "RenderParser.h"
#include "jpointers.h"

using namespace nlohmann;

RenderParser::RenderParser(std::string jsonStr) {
    json j = json::parse(jsonStr);

    // Camera
    double camera_pos[3];
    j.at("camera").at("position").get_to(camera_pos);
    camera_ptr camera = std::make_shared<Camera>(camera_pos);

    // Screen
    double height, width;
    j.at("screen").at("height").get_to(height);
    j.at("screen").at("width").get_to(width);
    screen_ptr screen = std::make_shared<Screen>(height, width);

    // Make light source
    double lightPos[3];
    double lightAmb[3];
    double lightDiff[3];
    double lightSpec[3];
    j.at("light").at("position").get_to(lightPos);
    j.at("light").at("ambient").get_to(lightAmb);
    j.at("light").at("diffuse").get_to(lightDiff);
    j.at("light").at("specular").get_to(lightSpec);
    light_ptr light = std::make_shared<Light>(lightPos, lightAmb, lightDiff, lightSpec);

    // Objects
    obj_vector objects;

    for (auto obj : j.at("objects")) {
        if (obj.at("type") == "sphere") {
            double position[3];
            double ambient[3];
            double diffuse[3];
            double specular[3];
            double shininess;
            double reflection;
            double radius;

            obj.at("position").get_to(position);
            obj.at("ambient").get_to(ambient);
            obj.at("diffuse").get_to(diffuse);
            obj.at("specular").get_to(specular);
            obj.at("shininess").get_to(shininess);
            obj.at("reflection").get_to(reflection);
            obj.at("radius").get_to(radius);

            sphere_ptr sphere = std::make_shared<Sphere>(position, ambient, diffuse, specular, shininess,
            reflection, radius);

            // std::cout << "obj: " << sphere << std::endl;
            objects.push_back(reinterpret_pointer_cast<Object>(sphere));
        }
    }

    render_ = std::make_shared<Render>(objects, camera, screen, light);
}

std::shared_ptr<Render> RenderParser::getRender() {
    return render_;
}
