cmake_minimum_required(VERSION 3.16.0)
include(CMakePrintHelpers)
project(jelorender VERSION 1.0.0 LANGUAGES CXX C)

# Cmake paramters
set(default_build_type "RelWithDebInfo")
set(CMAKE_C_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_RELEASE "-DNDEBUG -O2") 
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELEASE} -g")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_C_FLAGS_RELWITHDEBINFO})
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Dependencies
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(
    Boost
    COMPONENTS program_options log
    REQUIRED
)

# Executable
add_executable(
    jrender
    src/main.cpp
    src/Camera.cpp
    src/Screen.cpp
    src/Light.cpp
    src/Object.cpp
    src/Sphere.cpp
    src/Render.cpp
    src/RenderParser.cpp
)

target_compile_features (
    jrender
    PRIVATE
        cxx_std_11
)

target_compile_options (
    jrender
    PRIVATE
        -Wall
        -Wno-misleading-indentation
)

target_include_directories (
    jrender
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        /usr/include/png++/
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
    jrender
    PRIVATE
        Threads::Threads
        m
        png
        ${Boost_LIBRARIES}
)

# Tests
add_executable(
    unit_tests 
    test/test_units.cpp
    src/Camera.cpp
    src/Screen.cpp
    src/Light.cpp
    src/Object.cpp
    src/Sphere.cpp
    src/Render.cpp
    src/RenderParser.cpp
)

# indicates the include paths
target_include_directories(
    unit_tests 
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        /usr/include/png++/
        ${Boost_INCLUDE_DIRS}
)

# indicates the shared library variant
target_compile_definitions(
    unit_tests 
    PRIVATE 
        "BOOST_TEST_DYN_LINK=1"
)

# indicates the link paths
target_link_libraries(
    unit_tests 
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    m
    png
    ${Boost_LIBRARIES}
)

add_test(NAME unit_tests COMMAND unit_tests)