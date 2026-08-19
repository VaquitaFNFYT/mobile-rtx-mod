cmake_minimum_required(VERSION 3.25)

# Si se define CLI_GEODE_SDK (como lo hace GitHub Actions), se lo pasamos a CMAKE_PREFIX_PATH
if(DEFINED ENV{CLI_GEODE_SDK})
    set(GEODE_SDK $ENV{CLI_GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
elseif(DEFINED GEODE_SDK)
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
endif()

project(nombre_de_tu_mod)

find_package(Geode REQUIRED)
include_directories(${GEODE_INCLUDE_DIR})

# Resto de tu configuración (setup_geode_mod, etc.)
