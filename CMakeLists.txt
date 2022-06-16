cmake_minimum_required(VERSION 3.22)
project(graphicsEngine)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BINARY_DIR "release/") 
set(CMAKE_SOURCE_DIR "src/")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR})
add_executable(graphicsEngine ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/glad.c)

# OpenGL (GLAD) & GLFW Libraries
target_link_libraries(graphicsEngine PUBLIC dl)
target_link_libraries(graphicsEngine PUBLIC GL)
target_link_libraries(graphicsEngine PUBLIC glfw)
