#define BOOST_TEST_MODULE Units
#include <boost/test/included/unit_test.hpp>
#include "Render.h"
#include "Sphere.h"
#include "tnt_ops.h"

namespace utf = boost::unit_test;
namespace tt = boost::test_tools;

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768

BOOST_AUTO_TEST_CASE(normalize_vector, * utf::tolerance(0.01))
{
    double_1darray test(3, 1.0);
    double_1darray normTest = normalizeVector(test);
    BOOST_CHECK(normTest[0] == 0.5773502691896258);
    BOOST_CHECK(normTest[1] == 0.5773502691896258);
    BOOST_CHECK(normTest[2] == 0.5773502691896258);
}


BOOST_AUTO_TEST_CASE(dot_product, * utf::tolerance(0.001))
{
    double_1darray test1(3, 1.0);
    double_1darray test2(3, 2.0);
    double dotTest = dotProduct(test1, test2);

    BOOST_CHECK(dotTest == 6.0);
}


BOOST_AUTO_TEST_CASE(reflect_vector, * utf::tolerance(0.001))
{
    double_1darray test3(3, 2.0);
    double_1darray test4(3, 1.0);
    double_1darray reflTest = reflectVector(test3, test4);

    BOOST_CHECK(reflTest[0] == -10.0);
    BOOST_CHECK(reflTest[1] == -10.0);
    BOOST_CHECK(reflTest[2] == -10.0);
}


BOOST_AUTO_TEST_CASE(nearest_intersected_object, * utf::tolerance(0.001))
{
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

    double position1[3] = {-0.2, 0., -1}; 
    double ambient1[3] = {0.1, 0., 0.};
    double diffuse1[3] = {0.7, 0., 0.};
    double specular1[3] = {1.0, 1.0, 1.0};
    Sphere sphere1(position1, ambient1, diffuse1, specular1, 100, 0.5, 0.7);

    double position2[3] = {0.1, -0.3, 0};
    double ambient2[3] = {0.1, 0., 0.1};
    double diffuse2[3] = {0.7, 0., 0.7};
    double specular2[3] = {1.0, 1.0, 1.0};
    Sphere sphere2(position2, ambient2, diffuse2, specular2, 100, 0.5, 0.1);

    double position3[3] = {-0.3, 0, 0}; 
    double ambient3[3] = {0.0, 0.1, 0.0};
    double diffuse3[3] = {0.0, 0.6, 0.0};
    double specular3[3] = {1.0, 1.0, 1.0};
    Sphere sphere3(position3, ambient3, diffuse3, specular3, 100, 0.5, 0.15);

    double position4[3] = {0, -9000, 0}; 
    double ambient4[3] = {0.1, 0.1, 0.1};
    double diffuse4[3] = {0.6, 0.6, 0.6};
    double specular4[3] = {1.0, 1.0, 1.0};
    Sphere sphere4(position4, ambient4, diffuse4, specular4, 100, 0.5, 9000.0 - 0.7);

    objects.push_back(reinterpret_cast<Object*>(&sphere1));
    objects.push_back(reinterpret_cast<Object*>(&sphere2));
    objects.push_back(reinterpret_cast<Object*>(&sphere3));
    objects.push_back(reinterpret_cast<Object*>(&sphere4));

    Render render(objects, camera, screen, light);

    double_1darray origin(3, 0.0);
    origin[2] = 1.0;
    
    double_1darray direction(3, 0.0);
    direction[0] = -0.10482848;
    direction[1] = 0.31448545;
    direction[2] = -0.94345635;

    auto result = render.nearestIntersectedObject(origin, direction);

    /*
    ({'center': array([-0.2,  0. , -1. ]),
      'radius': 0.7,
      'ambient': array([0.1, 0. , 0. ]),
      'diffuse': array([0.7, 0. , 0. ]),
      'specular': array([1, 1, 1]),
      'shininess': 100,
      'reflection': 0.5},
     1.60787843946078) */

    BOOST_CHECK(result.first != nullptr);
    Sphere* s = reinterpret_cast<Sphere*>(result.first);

    BOOST_CHECK(result.second == 1.60787843946078);
    BOOST_CHECK(s->getRadius() == 0.7);
}