#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphics/gui/gui.hpp"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>

namespace graphics 
{

struct Window 
{
public:
    Window(const Window&) = delete;
    auto operator=(const Window&) = delete;

    Window(int32_t width, int32_t height);

    GLFWwindow* get_win_ptr() const noexcept;
    void set_win_ptr(GLFWwindow* window);
    std::unique_ptr<ui::Gui>& get_gui() noexcept;
    void set_gui(std::unique_ptr<ui::Gui> gui) noexcept;
    int32_t* get_width_ptr() noexcept;
    const int32_t get_width() const noexcept;
    void set_width(int32_t width);
    int32_t* get_height_ptr() noexcept;
    const int32_t get_height() const noexcept;
    void set_height(int32_t height);
    double* get_mouse_pos_x_ptr() noexcept;
    double* get_mouse_pos_y_ptr() noexcept;

private:
    GLFWwindow* m_window;
    std::unique_ptr<ui::Gui> m_gui;
    int32_t m_width;
    int32_t m_height;
    double m_mouse_pos_x;
    double m_mouse_pos_y;
};
} // namespace graphics

#endif