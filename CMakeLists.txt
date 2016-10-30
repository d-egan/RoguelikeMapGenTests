cmake_minimum_required(VERSION 3.6)
project(mapGen)


set(SOURCE_FILES src/main.cpp src/Map.cpp include/Map.h src/Tile.cpp include/Tile.h src/Part.cpp include/Part.h src/BSPGenerator.cpp include/BSPGenerator.h src/RWGenerator.cpp include/RWGenerator.h)
set(EXECUTABLE_NAME "mapGen")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message("Source dir: " ${CMAKE_SOURCE_DIR})
message("Module Path: " ${CMAKE_MODULE_PATH})

message("Executable name: " ${EXECUTABLE_NAME})




find_package(LIBTCOD REQUIRED)
if (LIBTCOD_FOUND)
    message("Include Dir: " ${LIBTCOD_INCLUDE_DIR})
    message("Libraries : " ${LIBTCOD_LIBRARIES})

    include_directories(${LIBTCOD_INCLUDE_DIRS})
    target_link_libraries (${EXECUTABLE_NAME} ${LIBTCOD_LIBRARIES})
endif (LIBTCOD_FOUND)

find_package(LIBTCODXX REQUIRED)
if (LIBTCODXX_FOUND)
    message("EInclude Dir: " ${LIBTCODXX_INCLUDE_DIR})
    message("Libraries  : " ${LIBTCODXX_LIBRARIES})

    include_directories(${LIBTCODXX_INCLUDE_DIRS})
    target_link_libraries (${EXECUTABLE_NAME} ${LIBTCODXX_LIBRARIES})
endif (LIBTCODXX_FOUND)