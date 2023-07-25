#ifndef WINDOWUTILITY_HPP
#define WINDOWUTILITY_HPP

#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>

#include "window.hpp"

namespace backend {

/**
 * @brief WindowUtility
 *
 * @par Utility class with no state
 * Used as an interface between \class Window common functions and glfw
 * windowing system.
 *
 */
class WindowUtility {
public:
    /**
    * @brief Create a glfw window and assign it to a \class Window object
    *
    * @param window the \class Window object which receives the glfw window
    * instance.
    * @param width the width of the glfw window to be created.
    * @param height the height of the glfw window to be created.
    * @return true if the window was created succesfully.
    * @return false otherwise.
    */
    static bool create_window(Window &window, int32_t width, int32_t height);

    /**
    * @brief Destroy the glfw window assigned to a \class Window object
    *
    * @param window the \class Window object which holds the glfw window
    * instance.
    * @return true if the window was destroyed succesfully.
    * @return false otherwise.
    */
    static bool destroy_window(Window &window);

    /**
    * @brief Checks if the \class Window object has been initialized
    *
    * @param window the \class Window object
    */
    static const bool is_initialized(Window &window) noexcept;

    /**
    * @brief Check if the \class Window object is currently active and has thread
    *
    * @param window the \class Window to check.
    * @return true if the window is open
    * @return false
    */
    static bool is_open(Window &window);

    /**
    * @brief Swap the front and back buffers of the window
    *
    * @param window the \class Window object
    */
    static void swap_buffers(Window &window);

    /**
    * @brief Polls events from queue for current \class Window object owning
    * context
    *
    */
    static void poll_events();

    /**
    * @brief Makes context current for the \class Window object
    *
    * @param window the \class Window object
    */
    static void make_context_current(Window &window);

    /**
    * @brief Fills \class Window object size fields
    *
    * @param window the \class Window object
    */
    static void get_window_size(Window &window);

    /**
    * @brief Fills mouse cursor position for the \class Window object
    *
    * @param window the \class Window object
    */
    static void get_mouse_pos(Window &window);

    /**
     * @brief Set the glfw log object and prints it as debug
     * 
     */
    static void set_log_callback();

    /**
     * @brief Set the error log callback for the glfw functions
     * 
     * @param error the number of the error
     * @param description the description
     */
    static void glfwErrorCallback(int error, const char* description);
};
} // namespace backend

#endif