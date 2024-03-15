cmake_minimum_required(VERSION 3.20)
project(Cairo LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -frecord-gcc-switches -Wall -Wextra -pedantic")

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0 REQUIRED)

set(CMAKE_PREFIX_PATH /app/3rdparty/cyclonedds-0.10.4/cyclonedds-0.10.4 
                        /app/3rdparty/cyclonedds-0.10.4/cyclonedds-cxx-0.10.4)
find_package(CycloneDDS-CXX REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

FILE(GLOB_RECURSE APP_SOURCES ${PROJECT_SOURCE_DIR}/src/*.hpp ${PROJECT_SOURCE_DIR}/src/*.cpp)

set(SOURCES ${APP_SOURCES})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} CycloneDDS-CXX::ddscxx)
