cmake_minimum_required(VERSION 3.11)
project(OOP_indie_studio_2019 CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/packages")
set(Irrlicht_FIND_REQUIRED True)
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets/")

include(FindIrrlicht)

include_directories(${Irrlicht_INCLUDE_DIRS})
include_directories(./include)

file(GLOB_RECURSE BOMBERMAN_SRC PATH ./sources/*.cpp)

add_executable(bomberman
    ${BOMBERMAN_SRC}
)

add_definitions(-DASSETS="${ASSETS_DIR}")
target_link_libraries(bomberman Irrlicht pthread sfml-audio)