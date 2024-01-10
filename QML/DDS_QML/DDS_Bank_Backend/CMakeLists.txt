cmake_minimum_required(VERSION 3.5)

project(DDS_Bank_Backend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------------------- DDS --------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)
find_package(RTIConnextDDS "6.1.0" REQUIRED COMPONENTS core routing_service)
# ----------------------------------------------- DDS --------------------------------------------------------

# ------------------------------------------- IDL to C++ -----------------------------------------------------
# Configura la ubicación de los archivos IDL
set(IDL_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/
    )

# Buscar todos los archivos con extensión .idl en la ruta especificada
file(GLOB IDL_FILES ${IDL_DIRECTORY}*.idl)

message(STATUS "IDLs founded: ${IDL_FILES}")

# Configura la ubicación de la herramienta de generación de código
set(CODE_GEN_TOOL rtiddsgen)
# TODO: No se como se imprime la arquitectura que tiene el sistema
set(ARCHITECTURE_TO_DDS x64Linux4gcc7.3.0)

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

    set(GENERATED_MAKEFILE makefile_${IDL_BASENAME}_${ARCHITECTURE_TO_DDS})
    set(GENERATED_README  README_${ARCHITECTURE_TO_DDS}.txt)

    # Agregar el comando personalizado
    add_custom_command(
        OUTPUT ${GENERATED_CXX_FILE} ${GENERATED_HPP_FILE} ${GENERATED_CXX_PLUGIN_FILE} ${GENERATED_HPP_PLUGIN_FILE}
        COMMAND ${CODE_GEN_TOOL} -language c++11 -platform ${ARCHITECTURE_TO_DDS} -create makefiles -create typefiles ${IDL_FILES}
            && rm ${GENERATED_MAKEFILE} ${GENERATED_README} #TODO: Mirar como no generar el makefile y README (no lo he encontrado)
        WORKING_DIRECTORY ${GENERATED_CODE_DIR}
        )

    # Agrego los archivos a la lista
    list(APPEND GENERATED_IDL_FILES
        ${GENERATED_CXX_FILE}
        ${GENERATED_HPP_FILE}
        ${GENERATED_CXX_PLUGIN_FILE}
        ${GENERATED_HPP_PLUGIN_FILE}
        )
    message(STATUS GENERATED_IDL_FILES: ${GENERATED_IDL_FILES})

endforeach()

set(GENERATED_TEST_FILE ${PROJECT_SOURCE_DIR}/test.txt)
add_custom_command(
    OUTPUT GENERATED_TEST_FILE
    COMMAND touch test.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )

# ------------------------------------------- IDL to C++ -----------------------------------------------------

set(PROJECT_SOURCES
    ${GENERATED_IDL_FILES}
    main.cpp
    application.hpp
    subscriber.hpp subscriber.cpp
    bankmodel.hpp bankmodel.cpp
    buckettype.hpp
    )

add_executable(DDS_Bank_Backend
    ${PROJECT_SOURCES}
    )

target_link_libraries(DDS_Bank_Backend
    PUBLIC RTIConnextDDS::cpp2_api
    )
