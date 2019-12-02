cmake_minimum_required(VERSION 3.15)
project(Eigenfaces)

set(CMAKE_CXX_STANDARD 14)

add_executable(Eigenfaces main.cpp reader.h reader.cpp pca.cpp pca.h Eigenv.cpp Eigenv.h)