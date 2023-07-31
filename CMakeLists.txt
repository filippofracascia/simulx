cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # enforce C++17
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(GRAPHICS_CONTEXT "OPENGL" CACHE STRING "Set the graphics context")
add_definitions(-DGRAPHICS_CONTEXT=${GRAPHICS_CONTEXT})
message(STATUS "Using graphics context: ${GRAPHICS_CONTEXT}")

set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)

set(BITMAPS_DIR ${ASSETS_DIR}/bitmaps)
set(FONTS_DIR ${ASSETS_DIR}/fonts)
set(SHADERS_DIR ${ASSETS_DIR}/shaders)

add_definitions(-DSHADERS_DIR="${SHADERS_DIR}")
message(STATUS "Shaders directory found at: ${SHADERS_DIR}")

project(simulator)

set(INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include
                        ${CMAKE_SOURCE_DIR}/submodules/imgui
                        ${CMAKE_SOURCE_DIR}/submodules/glfw/include
                        ${CMAKE_SOURCE_DIR}
                        )

set(LIB_DIRECTORIES ${CMAKE_SOURCE_DIR}/submodules/glfw/build/src)

add_executable(simulator main.cpp)

add_subdirectory(common)
add_subdirectory(graphics)
#add_subdirectory(frontend)

target_include_directories(simulator PRIVATE ${INCLUDE_DIRECTORIES})
target_link_directories(simulator PRIVATE ${LIB_DIRECTORIES})

target_link_libraries(simulator -lGL -lXrandr -lXi -lglfw3)