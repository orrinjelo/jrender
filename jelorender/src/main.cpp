#include <iostream>
#include <fstream>
#include <boost/log/trivial.hpp>

#include "Camera.h"
#include "Screen.h"
#include "Light.h"
#include "Sphere.h"
#include "Render.h"
#include "tnt_ops.h"
#include "RenderParser.h"

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768

void init()
{
    // logging::core::get()->set_filter
    // (
    //     logging::trivial::severity >= logging::trivial::info
    // );
}

int main(int argc, char* argv[]) {
    init();
    // Make camera and screen
    // Camera camera({0, 0, 1});
    // Screen screen(IMAGE_HEIGHT, IMAGE_WIDTH);
    
    // // Make light source
    // double lightPos[3] = {5.0, 5.0, 5.0};
    // double lightAmb[3] = {1.0, 1.0, 1.0};
    // double lightDiff[3] = {1.0, 1.0, 1.0};
    // double lightSpec[3] = {1.0, 1.0, 1.0};
    // Light light(lightPos, lightAmb, lightDiff, lightSpec);
    
    // // Make objects
    // obj_vector objects;

    // double position1[3] = {-0.2, 0., -1}; 
    // double ambient1[3] = {0.1, 0., 0.};
    // double diffuse1[3] = {0.7, 0., 0.};
    // double specular1[3] = {1.0, 1.0, 1.0};
    // Sphere sphere1(position1, ambient1, diffuse1, specular1, 100, 0.5, 0.7);

    // double position2[3] = {0.1, -0.3, 0};
    // double ambient2[3] = {0.1, 0., 0.1};
    // double diffuse2[3] = {0.7, 0., 0.7};
    // double specular2[3] = {1.0, 1.0, 1.0};
    // Sphere sphere2(position2, ambient2, diffuse2, specular2, 100, 0.5, 0.1);

    // double position3[3] = {-0.3, 0, 0}; 
    // double ambient3[3] = {0.0, 0.1, 0.0};
    // double diffuse3[3] = {0.0, 0.6, 0.0};
    // double specular3[3] = {1.0, 1.0, 1.0};
    // Sphere sphere3(position3, ambient3, diffuse3, specular3, 100, 0.5, 0.15);

    // double position4[3] = {0, -9000, 0}; 
    // double ambient4[3] = {0.1, 0.1, 0.1};
    // double diffuse4[3] = {0.6, 0.6, 0.6};
    // double specular4[3] = {1.0, 1.0, 1.0};
    // Sphere sphere4(position4, ambient4, diffuse4, specular4, 100, 0.5, 9000.0 - 0.7);

    // objects.push_back(reinterpret_cast<Object*>(&sphere1));
    // objects.push_back(reinterpret_cast<Object*>(&sphere2));
    // objects.push_back(reinterpret_cast<Object*>(&sphere3));
    // objects.push_back(reinterpret_cast<Object*>(&sphere4));

    // Render render(objects, camera, screen, light);

    // render.generate("jrender.png");

    std::ifstream infile("example.json");
    std::string json, str;
    while (std::getline(infile, str))
    {
      json += str;
      json.push_back('\n');
    }
    RenderParser renderp(json);
    renderp.getRender()->generate("jrender2.png");

    return 0;
}
