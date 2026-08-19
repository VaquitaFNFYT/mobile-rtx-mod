cmake_minimum_required(VERSION 3.25)

project(mobile-rtx-mod)

# Le indicamos a CMake dónde encontrar la configuración del SDK de Geode
if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
elseif(DEFINED ENV{CLI_GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{CLI_GEODE_SDK}")
endif()

find_package(Geode REQUIRED CONFIG)

setup_geode_mod(${PROJECT_NAME})
