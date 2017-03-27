cmake_minimum_required(VERSION 3.6)
project(mapGen)
set(CMALE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Map.cpp include/Map.h src/Tile.cpp include/Tile.h src/Part.cpp include/Part.h src/BSPGenerator.cpp include/BSPGenerator.h src/RWGenerator.cpp include/RWGenerator.h src/DRandom.cpp include/DRandom.h src/Walker.cpp include/Walker.h include/SpriteType.h)

set(EXECUTABLE_NAME "mapGen")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

message("Source dir: " ${CMAKE_SOURCE_DIR})
message("Module Path: " ${CMAKE_MODULE_PATH})

message("Executable name: " ${EXECUTABLE_NAME})

find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
