cmake_minimum_required(VERSION 3.14)

project(Prueba03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

# ------------------------------------------- DDS Libraries --------------------------------------------------
# Definiciones de compilación
add_compile_definitions(
    RTI_UNIX
    RTI_LINUX
    RTI_64BIT
)

# The RTI CMake Module package depends on NDDSHOME environment variable.
# Include the path to the CMAKE_MODULE_PATH
# The NDDSHOME variable must be set on the configuration environment
# or provided to the cmake
list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)
message(STATUS "El directorio general es: ${CMAKE_CURRENT_SOURCE_DIR}")

# Configuración de directorios de inclusión y bibliotecas
set(TARGET_ARCH "x64Linux4gcc7.3.0")
include_directories(
    .
    $ENV{NDDSHOME}/include
    $ENV{NDDSHOME}/include/ndds
    $ENV{NDDSHOME}/include/ndds/hpp
)
link_directories($ENV{NDDSHOME}/lib/${TARGET_ARCH})
# ------------------------------------------- DDS Libraries --------------------------------------------------

# ------------------------------------------- IDL to C++ -----------------------------------------------------
# Configura la ubicación de los archivos IDL
set(IDL_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/
)

# Buscar todos los archivos con extensión .idl en la ruta especificada
file(GLOB IDL_FILES ${IDL_DIRECTORY}*.idl)

message(STATUS "Archivos idl encontrados: ${IDL_FILES}")

# Configura la ubicación de la herramienta de generación de código
set(CODE_GEN_TOOL rtiddsgen)

# Configura la ubicación del directorio de salida para el código generado
set(GENERATED_CODE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Creamos una lista con todos los archivos generados para luego agregarlas al ejecutable
set(GENERATED_IDL_FILES)

# Iterar sobre cada archivo IDL encontrado
foreach(IDL_FILE ${IDL_FILES})
    # Extraer el nombre base del archivo IDL
    get_filename_component(IDL_BASENAME ${IDL_FILE} NAME_WE)

    # Construir los nombres de los archivos generados
    set(GENERATED_CXX_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}.cxx)
    set(GENERATED_HPP_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}.hpp)
    set(GENERATED_CXX_PLUGIN_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}Plugin.cxx)
    set(GENERATED_HPP_PLUGIN_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}Plugin.hpp)

    # Agregar el comando personalizado
    add_custom_command(
        OUTPUT ${GENERATED_CXX_FILE} ${GENERATED_HPP_FILE} ${GENERATED_CXX_PLUGIN_FILE} ${GENERATED_HPP_PLUGIN_FILE}
        COMMAND ${CODE_GEN_TOOL} -language c++11 -platform x64Linux4gcc7.3.0 -create makefiles -create typefiles ${IDL_FILES}
        WORKING_DIRECTORY ${GENERATED_CODE_DIR}
    )

    # Agrego los archivos a la lista
    list(APPEND GENERATED_IDL_FILES
        ${GENERATED_CXX_FILE}
        ${GENERATED_HPP_FILE}
        ${GENERATED_CXX_PLUGIN_FILE}
        ${GENERATED_HPP_PLUGIN_FILE}
    )

endforeach()
# ------------------------------------------- IDL to C++ -----------------------------------------------------

# ------------------------------------------- Link Libraries -------------------------------------------------
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

# Defino las opciones del compilador
set(SYSLIBS -ldl -lm -lpthread -lrt -no-pie -rdynamic)

# Definir las bibliotecas de NDDS
set(NDDS_LIBRARIES
    -L$ENV{NDDSHOME}/lib/${TARGET_ARCH}
    -lnddscpp2${SHAREDLIB_SFX}${DEBUG_SFX}
    -lnddsc${SHAREDLIB_SFX}${DEBUG_SFX}
    -lnddscore${SHAREDLIB_SFX}${DEBUG_SFX}
)

# Definir las bibliotecas finales
set(LIBS ${NDDS_LIBRARIES} ${SYSLIBS})
# ------------------------------------------- Link Libraries -------------------------------------------------

set(PROJECT_SOURCES
        ${GENERATED_IDL_FILES}
        main.cpp
        qml.qrc
        publisher.cpp
        application.hpp
)

message(STATUS "PROJECT_SOURCES: ${PROJECT_SOURCES}")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Prueba03
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Prueba03 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Prueba03 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Prueba03
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(Prueba03
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Prueba03
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  ${LIBS}
)

set_target_properties(Prueba03 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(Prueba03)
    qt_finalize_executable(Prueba03)
endif()
