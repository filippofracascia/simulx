#include <cstddef>
#include <memory>

#include "common/logger.hpp"
#include "window_utility.hpp"

namespace graphics 
{

bool WindowUtility::create_window(Window& window, int32_t width, int32_t height)
{
#if defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == OPENGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    GLFWwindow* winPtr = nullptr;
    if ((winPtr = glfwCreateWindow(width, height, "simulx", NULL, NULL)) == NULL)
    {
        return false;
    } 
    else 
    {
        window.set_win_ptr(winPtr);
        return true;
    }
}
/// @todo: implement error handling for glfw.
bool WindowUtility::destroy_window(Window& window)
{
    if (is_initialized(window)) 
    {
        glfwDestroyWindow(window.get_win_ptr());
        return true;
    }
    return false;
}
const bool WindowUtility::is_initialized(Window& window) noexcept
{
    return window.get_win_ptr() != nullptr;
}
bool WindowUtility::is_open(Window& window)
{
    return is_initialized(window) && !glfwWindowShouldClose(window.get_win_ptr());
}
void WindowUtility::set_bg_color(const std::array<float, 4>& background)
{
    glClearColor(background[0], background[1], background[2], background[3]);
}
void WindowUtility::color_bg()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
void WindowUtility::swap_buffers(Window& window)
{
    glfwSwapBuffers(window.get_win_ptr());
}
void WindowUtility::poll_events()
{
    glfwPollEvents();
}
void WindowUtility::make_context_current(Window& window)
{
    glfwMakeContextCurrent(window.get_win_ptr());
}
void WindowUtility::get_window_size(Window& window)
{
    if (is_initialized(window)) 
    {
        glfwGetWindowSize(window.get_win_ptr(), window.get_width_ptr(), window.get_height_ptr());
    }
}
void WindowUtility::get_mouse_pos(Window& window)
{
    if (is_initialized(window)) 
    {
        glfwGetCursorPos(window.get_win_ptr(), window.get_mouse_pos_x_ptr(), window.get_mouse_pos_y_ptr());
    }
}
void WindowUtility::set_log_callback()
{
    glfwSetErrorCallback(glfwErrorCallback);
}

void WindowUtility::glfwErrorCallback(int error, const char* description)
{
    auto logger = common::Logger::getInstance();
    logger->log(common::LogLevel::ERROR, "[GLFW ERROR ", error, "]: ", description);
}
}