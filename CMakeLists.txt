# Minimum version I don't know
cmake_minimum_required(VERSION 3.15)

project(subtiles)
#set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(subtiles/inc)
include_directories(subtiles/inc/datatypes)

# Qt specific configs
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(subtiles)
