cmake_minimum_required(VERSION 3.25)

project(mobile-rtx-mod)

# 1. Buscamos el SDK en cualquiera de las variables que pueda enviar GitHub
if(DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK $ENV{GEODE_SDK})
elseif(DEFINED ENV{CLI_GEODE_SDK})
    set(GEODE_SDK $ENV{CLI_GEODE_SDK})
endif()

# 2. Si encontramos la ruta, se la pasamos a CMake
if(DEFINED GEODE_SDK)
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
endif()

# 3. Buscamos el paquete de Geode de forma obligatoria
find_package(Geode REQUIRED)

# 4. Vinculamos tu mod con las macros oficiales de Geode
setup_geode_mod(${PROJECT_NAME})
