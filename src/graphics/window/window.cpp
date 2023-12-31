#include "window.hpp"

namespace graphics 
{

Window::Window(int32_t width, int32_t height)
    : m_width(width)
    , m_height(height)
{
}

GLFWwindow* Window::get_win_ptr() const noexcept
{
    return m_window;
}
void Window::set_win_ptr(GLFWwindow* window)
{
    m_window = std::move(window);
}
std::unique_ptr<ui::Gui>& Window::get_gui() noexcept
{
    return m_gui;
}
void Window::set_gui(std::unique_ptr<ui::Gui> gui) noexcept
{
    m_gui = std::move(gui);
}
int32_t* Window::get_width_ptr() noexcept
{
    return &m_width;
}
const int32_t Window::get_width() const noexcept
{
    return m_width;
}
void Window::set_width(int32_t width)
{
    m_width = width;
}
int32_t* Window::get_height_ptr() noexcept
{
    return &m_height;
}
const int32_t Window::get_height() const noexcept
{
    return m_height;
}
void Window::set_height(int32_t height)
{
    m_height = height;
}
double* Window::get_mouse_pos_x_ptr() noexcept
{
    return &m_mouse_pos_x;
}
double* Window::get_mouse_pos_y_ptr() noexcept
{
    return &m_mouse_pos_y;
}
}