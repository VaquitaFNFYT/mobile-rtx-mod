cmake_minimum_required(VERSION 3.13)

project(TuNombreDeMod VERSION 1.0.0)

# Esta línea define la ruta del SDK de Geode desde las variables de entorno
if (DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})
endif()

find_package(Geode REQUIRED)
