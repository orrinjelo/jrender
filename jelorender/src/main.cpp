#include <iostream>
#include <vector>
#include <memory>
#include "Camera.h"
#include "Screen.h"
#include "Light.h"
#include "Sphere.h"
#include "tnt_ops.h"

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768
#define MAX_DEPTH 3

typedef std::unique_ptr<Object> obj_ptr;
typedef std::vector<obj_ptr> obj_vector;

void run_tests();

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
    objects.push_back(
        std::make_unique<Sphere>(
            center,
            ambient,
            diffuse,
            specular,
            100.0,    // Shininess
            0.5,      // Reflection
            0.7       // Radius
        )
    );

    return 0;
}

void run_tests() {

    // Tests
    double_1darray test(3, 1.0);
    double_1darray normTest = normalizeVector(test);

    std::cout << "Norm Results: " << normTest << std::endl;

    double_1darray test1(3, 1.0);
    double_1darray test2(3, 2.0);
    double dotTest = dotProduct(test1, test2);

    std::cout << "Dot Results: " << dotTest << std::endl;

    double_1darray test3(3, 2.0);
    double_1darray test4(3, 1.0);
    double_1darray reflTest = reflectVector(test3, test4);

    std::cout << "Reflect Results: " << reflTest << std::endl;

    
}