# Project setup.
cmake_minimum_required(VERSION 3.27)
project(jackboxmodtoolpack)

# Just grab every source file.
file(GLOB_RECURSE SOURCES "source/*.cpp")

# Libraries.
find_package(nlohmann_json 3.12.0 REQUIRED)

# Create the executable and add the C files.
add_executable(${PROJECT_NAME} ${SOURCES})

# Include the source dir
include_directories("source/")

# Link with libs
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)