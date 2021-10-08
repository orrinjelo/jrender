#include <iostream>

#include "Camera.h"
#include "Screen.h"
#include "Light.h"
#include "Sphere.h"
#include "tnt_ops.h"

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768
#define MAX_DEPTH 3

int main(int argc, char* argv[]) {
    printf("Hello World!\n");

    // Make camera and screen
    Camera camera({0, 0, 1});
    Screen screen(IMAGE_HEIGHT, IMAGE_WIDTH);
    
    // Make light source
    double lightPos[3] = {5.0, 5.0, 5.0};
    double lightAmb[3] = {1.0, 1.0, 1.0};
    double lightDiff[3] = {1.0, 1.0, 1.0};
    double lightSpec[3] = {1.0, 1.0, 1.0};
    Light light(lightPos, lightAmb, lightDiff, lightSpec);
    
    // Make objects
    obj_vector objects;
    double center[3] = {-0.2, 0.0, 1.0};
    double ambient[3] = {0.1, 0.0, 0.0};
    double diffuse[3] = {0.7, 0.0, 0.0};
    double specular[3] = {1.0, 1.0, 1.0};

    Sphere sphere1(
            center,
            ambient,
            diffuse,
            specular,
            100.0,    // Shininess
            0.5,      // Reflection
            0.7       // Radius
        );
    objects.push_back(
        reinterpret_cast<Object*>(&sphere1)
    );

    return 0;
}
