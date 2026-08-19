cmake_minimum_required(VERSION 3.25)

    set(GEODE_SDK $ENV{CLI_GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
elseif(DEFINED GEODE_SDK)
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
endif()

project()

find_package(Geode REQUIRED)
include_directories(${GEODE_INCLUDE_DIR})
 (setup_geode_mod, etc.)
