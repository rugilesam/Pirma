cmake_minimum_required(VERSION 3.24.3)
set(CMAKE_CXX_STANDARD 11)
project(pirmas.v1.0)

# Include directories
include_directories(include)

# Add your source files
file(GLOB SOURCES "src/*.cpp")

# Create an executable
add_executable(pirmas.v1.0 ${SOURCES})