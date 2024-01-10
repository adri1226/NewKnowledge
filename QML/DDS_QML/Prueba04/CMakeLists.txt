cmake_minimum_required(VERSION 3.14)

project(Prueba04 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)
find_package(RTIConnextDDS "6.1.0" REQUIRED COMPONENTS core routing_service)

set(CMAKE_CXX_FLAGS "-Wall -g")

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        application.hpp
#        publisher.cpp
        own_topics.hpp
        own_topics.cxx
        own_topicsPlugin.hpp
        own_topicsPlugin.cxx
        USER_QOS_PROFILES.xml
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Prueba04
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Prueba04 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Prueba04 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Prueba04
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(Prueba04
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Prueba04
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  PUBLIC RTIConnextDDS::cpp2_api
)

set_target_properties(Prueba04 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(Prueba04)
    qt_finalize_executable(Prueba04)
endif()
