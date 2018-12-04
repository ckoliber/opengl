cmake_minimum_required(VERSION 3.12)
project(TestC C)

set(CMAKE_C_STANDARD 99)

include_directories(TestC include)

add_executable(TestC
        src/window.c
#        example_triangle.c
#        example_cube.c
#        example_animate.c
        example_light.c
)

target_link_libraries(TestC -lfreeglut -lopengl32 -lglu32)