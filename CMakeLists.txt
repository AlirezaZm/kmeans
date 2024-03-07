set(CMAKE_CXX_COMPILER "clang++")
cmake_minimum_required(VERSION 3.5)
project(kmeans_version1 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB MAINSOURCE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)
file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/base.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/kmeans.cpp"
)
file(GLOB HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/kmeans.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/base.h"
)


add_library(kmeans ${SOURCES})
add_executable(main ${MAINSOURCE})
target_link_libraries(main PUBLIC kmeans)
target_compile_options(kmeans PRIVATE
    -O2
    -march=native
    -Rpass=loop-vectorize
    -Rpass-missed=loop-vectorize
    -Rpass-analysis=loop-vectorize
    -fsave-optimization-record
    -gline-tables-only
    -gcolumn-info
)