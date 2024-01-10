cmake_minimum_required(VERSION 3.5)

project(TresEnRaya LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Anadido para que encuentre todos los archivos solo
file(GLOB_RECURSE
    FOUND_FILES
    LIST_DIRECTORIES true
    src/*.*)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

message(STATUS ${FOUND_FILES})

add_executable(TresEnRaya main.cpp ${FOUND_FILES})
add_executable(TresEnRayaTest maintest.cpp ${FOUND_FILES})
target_link_libraries(TresEnRaya Threads::Threads )
target_link_libraries(TresEnRayaTest Threads::Threads )
