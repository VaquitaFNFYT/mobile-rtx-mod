cmake_minimum_required(VERSION 3.25)

project(mobile-rtx-mod)

if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
elseif(DEFINED ENV{CLI_GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{CLI_GEODE_SDK}")
else()

    list(APPEND CMAKE_PREFIX_PATH "/opt/geode")
endif()

find_package(Geode REQUIRED)

setup_geode_mod(${PROJECT_NAME})
