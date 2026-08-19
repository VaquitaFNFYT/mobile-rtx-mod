cmake_minimum_required(VERSION 3.25)

project(mobile-rtx-mod)

if(DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK $ENV{GEODE_SDK})
elseif(DEFINED ENV{CLI_GEODE_SDK})
    set(GEODE_SDK $ENV{CLI_GEODE_SDK})
endif()

if(DEFINED GEODE_SDK)
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
    include("${GEODE_SDK}/share/geode/cmake/GeodeFile.cmake" OPTIONAL)
endif()

find_package(Geode REQUIRED)

setup_geode_mod(${PROJECT_NAME})
