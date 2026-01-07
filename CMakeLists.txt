cmake_minimum_required(VERSION 4.0)
project(ada-eval-02)

set(CMAKE_CXX_STANDARD 23)

add_executable(ada-eval-02 main.cpp funciones.cpp estructuras.h)

if(OpenMP_CXX_FOUND)
    target_link_libraries(ada-eval-02 PUBLIC OpenMP::OpenMP_CXX)
endif()
