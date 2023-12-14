cmake_minimum_required(VERSION 3.26)
project(Engine3D)

set(CMAKE_CXX_STANDARD 17)

add_executable(Engine3D app/main.cpp
        include/matrix.hpp
        test/matrix_test.hpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Engine3D sfml-system sfml-window sfml-graphics)
