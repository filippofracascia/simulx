set(GRAPHICS_CONTEXT "OPENGL" CACHE STRING "Set the graphics context")
add_definitions(-DGRAPHICS_CONTEXT=${GRAPHICS_CONTEXT})
message(STATUS "Using graphics context: ${GRAPHICS_CONTEXT}")

set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)

set(BITMAPS_DIR ${ASSETS_DIR}/bitmaps)
set(FONTS_DIR ${ASSETS_DIR}/fonts)
set(SHADERS_DIR ${ASSETS_DIR}/shaders)

add_definitions(-DSHADERS_DIR="${SHADERS_DIR}")
message(STATUS "Shaders directory found at: ${SHADERS_DIR}")

add_definitions(-DFONTS_DIR="${FONTS_DIR}")
message(STATUS "Fonts directory found at: ${FONTS_DIR}")

set(INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include
                        ${CMAKE_SOURCE_DIR}/submodules/imgui
                        ${CMAKE_SOURCE_DIR}/submodules/glfw/include
                        ${CMAKE_SOURCE_DIR}/src
                        )

set(LIB_DIRECTORIES ${CMAKE_SOURCE_DIR}/submodules/glfw/build/src)

add_executable(simulator main.cpp)

add_subdirectory(common)
add_subdirectory(graphics)

target_include_directories(simulator PRIVATE ${INCLUDE_DIRECTORIES})
target_link_directories(simulator PRIVATE ${LIB_DIRECTORIES})

target_link_libraries(simulator -lGL -lXrandr -lXi -lglfw3)