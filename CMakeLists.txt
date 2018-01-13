cmake_minimum_required(VERSION 3.8)
project(jedlikGame)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp characters/Player.cpp headers/Player.h WorldObjects/World.cpp headers/World.h headers/WorldObject.h WorldObjects/Wall.cpp headers/Wall.h Utils/WorldUtils.cpp headers/WorldUtils.h headers/configs.h Utils/GameManager.cpp headers/GameManager.h WorldObjects/Pipe.cpp headers/Pipe.h)
add_executable(jedlikGame ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(jedlikGame ${SFML_LIBRARIES})
endif()