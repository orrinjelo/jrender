cmake_minimum_required(VERSION 3.18.0)
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

# Executable
add_executable(
    jrender
    src/main.cpp
    src/Camera.cpp
    src/Screen.cpp
    src/Light.cpp
    src/Object.cpp
    src/Sphere.cpp
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
)

target_link_libraries(
    jrender
    PRIVATE
        Threads::Threads
        m
)