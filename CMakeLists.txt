cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # enforce C++17
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(BACKEND_CONTEXT "OPENGL" CACHE STRING "Set the backend context")
add_definitions(-DBACKEND_CONTEXT=${BACKEND_CONTEXT})
message(STATUS "Using backend context: ${BACKEND_CONTEXT}")

project(simulator)

set(INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include
                        ${CMAKE_SOURCE_DIR}/submodules/glfw/include
                        ${CMAKE_SOURCE_DIR}/submodules/imgui
                        ${CMAKE_SOURCE_DIR}/submodules/glfw/include
                        ${CMAKE_SOURCE_DIR}
                        )

set(LIB_DIRECTORIES ${CMAKE_SOURCE_DIR}/submodules/glfw/build/src)

add_executable(simulator main.cpp)

add_subdirectory(common)
add_subdirectory(backend)
add_subdirectory(frontend)

target_include_directories(simulator PRIVATE ${INCLUDE_DIRECTORIES})
target_link_directories(simulator PRIVATE ${LIB_DIRECTORIES})

target_link_libraries(simulator -lGL -lXrandr -lXi -lglfw3)