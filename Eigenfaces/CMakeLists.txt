cmake_minimum_required(VERSION 3.15)
project(Eigenfaces)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
if (TARGET Eigen3::Eigen)
    # Use the imported target
endif (TARGET Eigen3::Eigen)
set(CMAKE_CXX_STANDARD 14)

add_executable(Eigenfaces main.cpp reader.h reader.cpp pca.cpp pca.h eigenv.h eigenv.cpp)
target_link_libraries (Eigenfaces Eigen3::Eigen)
