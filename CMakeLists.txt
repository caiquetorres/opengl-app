cmake_minimum_required(VERSION 3.23)
project(opengl)

set(CMAKE_CXX_STANDARD 14)

include(/Applications/vcpkg/scripts/buildsystems/vcpkg.cmake)

# # If the application calls OpenGL directly
find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

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

add_executable(opengl main.cpp ${HEADER_FILES} ${SOURCE_FILES})

# Link libraries and directories
target_link_libraries(opengl PRIVATE glad::glad)
target_link_libraries(opengl PRIVATE glfw)
target_link_libraries(opengl PRIVATE glm::glm)
target_link_libraries(opengl PRIVATE imgui::imgui)
target_include_directories(opengl PRIVATE ${Stb_INCLUDE_DIR})

# Copy resources
add_custom_target(
        copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/res
        ${PROJECT_BINARY_DIR}/res
        COMMENT "Copying resources into binary directory"
)

add_dependencies(opengl copy_resources)
