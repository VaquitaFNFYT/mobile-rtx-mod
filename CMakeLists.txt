cmake_minimum_required(VERSION 3.13)

project(mobile-rtx-mod VERSION 1.0.0)

if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
    list(APPEND CMAKE_MODULE_PATH "$ENV{GEODE_SDK}")
else()
    message(FATAL_ERROR "GEODE_SDK environment variable is not set!")
endif()

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    SRC
        src/main.cpp
)
