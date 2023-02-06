cmake_minimum_required(VERSION 3.23)
project(opengl)

set(CMAKE_CXX_STANDARD 14)

# If the application calls OpenGL directly
find_package(OpenGL REQUIRED)

# Add source files
file(
        GLOB_RECURSE
        SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.c)

# Add header files
file(
        GLOB_RECURSE
        HEADER_FILES
        ${CMAKE_SOURCE_DIR}/src/*.h
        ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glad EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

add_executable(opengl main.cpp ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(opengl glfw glad glm)