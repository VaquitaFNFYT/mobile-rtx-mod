cmake_minimum_required(VERSION 3.25)

if(DEFINED ENV{CLI_GEODE_SDK})
    set(GEODE_SDK $ENV{CLI_GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
elseif(DEFINED GEODE_SDK)
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
endif()

project(mobile-rtx-mod)

find_package(Geode REQUIRED)

setup_geode_mod(
    ${PROJECT_NAME}
)
