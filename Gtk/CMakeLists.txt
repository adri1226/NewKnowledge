cmake_minimum_required(VERSION 3.0.0)

project(PruebaDocker VERSION 0.1.0 LANGUAGES C CXX)

# Buscar la librería GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Especificar las rutas de inclusión
include_directories(${GTKMM_INCLUDE_DIRS})

# Lista con los archivos para incluir
file(GLOB_RECURSE SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/code/*.hpp
  ${PROJECT_SOURCE_DIR}/code/*.cpp
  )

message("TODOS LOS ARCHIVOS: " + ${SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})