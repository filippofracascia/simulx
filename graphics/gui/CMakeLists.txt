set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/submodules/imgui)
set(IMGUI_SOURCES ${IMGUI_DIR}/imgui.cpp
                  ${IMGUI_DIR}/imgui_draw.cpp
                  ${IMGUI_DIR}/imgui_tables.cpp
                  ${IMGUI_DIR}/imgui_widgets.cpp
                  ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
                  ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)

target_sources(simulator PRIVATE gui.cpp ${IMGUI_SOURCES})