cmake_minimal_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(src)

add_exectuble(
    a.out
    glad.c
    shaderClass.cpp
    VBO.cpp
    VAO.cpp
    EBO.cpp
    Textures.cpp
    Camera.cpp
    main.cpp
)