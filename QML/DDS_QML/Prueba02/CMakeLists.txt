cmake_minimum_required(VERSION 3.14)

project(Prueba02 VERSION 0.1 LANGUAGES CXX)

# Definiciones de compilación
add_compile_definitions(
    RTI_UNIX
    RTI_LINUX
    RTI_64BIT
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

# The RTI CMake Module package depends on NDDSHOME environment variable.
# Include the path to the CMAKE_MODULE_PATH
# The NDDSHOME variable must be set on the configuration environment
# or provided to the cmake
list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)

# Configuración de directorios
set(SOURCE_DIR "")
set(TARGET_ARCH "x64Linux4gcc7.3.0")

# Configuración del compilador
set(COMPILER g++)
set(COMPILER_FLAGS "-m64 -Wall -std=c++14")
set(LINKER ${COMPILER})
set(LINKER_FLAGS "-m64")

# Configuración de la compilación en modo debug
set(DEBUG 0)
if(${DEBUG})
    set(COMPILER_FLAGS "${COMPILER_FLAGS} -g -O0")
    set(LINKER_FLAGS "${LINKER_FLAGS} -g")
    set(DEBUG_SFX "d")
else()
    set(DEBUG_SFX "")
endif()

# Configuración de la compilación de bibliotecas compartidas
set(SHAREDLIB 0)
if(NOT ${SHAREDLIB})
    set(SHAREDLIB_SFX "z")
    add_compile_definitions(RTI_STATIC)
else()
    set(SHAREDLIB_SFX "")
endif()

# Configuración de directorios de inclusión y bibliotecas
#set(NDDSHOME "/opt/rtlib/rti_connext_dds-6.1.0")
include_directories(
    .
    $ENV{NDDSHOME}/include
    $ENV{NDDSHOME}/include/ndds
    $ENV{NDDSHOME}/include/ndds/hpp
)
link_directories($ENV{NDDSHOME}/lib/${TARGET_ARCH})

# Archivos fuente
set(CDRSOURCES chocolate_factory.idl)
set(SOURCES
    ${SOURCE_DIR}chocolate_factoryPlugin.cxx
    ${SOURCE_DIR}chocolate_factory.cxx
)
set(COMMONSOURCES
    ${SOURCES}
)

# Ejecutables
set(EXEC chocolate_factory_publisher)

# Objetos comunes
set(COMMONOBJS "")
foreach(SRC ${COMMONSOURCES})
    get_filename_component(OBJ ${SRC} NAME_WE)
    list(APPEND COMMONOBJS "objs/${TARGET_ARCH}/${OBJ}.o")
endforeach()

# Creación de ejecutables
foreach(EXE ${EXEC})
    add_executable(${EXE} ${COMMONOBJS} "objs/${TARGET_ARCH}/${EXE}.o")
    target_link_libraries(${EXE} nddscpp2${SHAREDLIB_SFX}${DEBUG_SFX} nddsc${SHAREDLIB_SFX}${DEBUG_SFX} nddscore${SHAREDLIB_SFX}${DEBUG_SFX} ${SYSLIBS})
endforeach()

# Reglas para compilación de objetos
foreach(SRC ${COMMONSOURCES})
    get_filename_component(OBJ ${SRC} NAME_WE)
    add_library(${OBJ} OBJECT ${SOURCE_DIR}${SRC})
    set_property(TARGET ${OBJ} PROPERTY COMPILE_FLAGS "${COMPILER_FLAGS} ${DEFINES}")
endforeach()

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        application.hpp

        chocolate_factory_publisher.cxx

        # Estas son autogeneradas al generar codigo de C++ del IDL, hay que mirar como hacer
        # automaticamente esta conversion y añadir estos elementos al PROJECT_SOURCE
#        chocolate_factory.hpp
#        chocolate_factory.cxx
#        chocolate_factoryPlugin.hpp
#        chocolate_factoryPlugin.cxx
)

# Creación de directorios
foreach(DIR objs.dir objs_${TARGET_ARCH}.dir)
    add_custom_target(${DIR}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DIR}
    )
endforeach()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Prueba02
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Prueba02 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Prueba02 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Prueba02
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(Prueba02
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Prueba02
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(Prueba02 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(Prueba02)
    qt_finalize_executable(Prueba02)
endif()
