cmake_minimum_required(VERSION 3.25)
include(FetchContent)

project(MobileRTX VERSION 1.0.0)

find_package(Geode REQUIRED)

setup_geode_mod(
    SOURCE_FILES 
        src/main.cpp
    RESOURCES
        resources/rtx_vert.glsl
        resources/rtx_frag.glsl
)
