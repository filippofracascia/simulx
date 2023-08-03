#include <algorithm>
#include <cstdint>
#include <memory>

#include "graphics/gui/main_gui.hpp"
#include "window_manager.hpp"

namespace graphics 
{

void WindowManager::init()
{
    mLogger = common::Logger::getInstance();

    if (!glfwInit()) {
        mLogger->log(common::FATAL, "[WindowManager][init] Error initializing glfw.");
        return;
    }
    mLogger->log(common::INFO, "[WindowManager][init] Successfully initialized glfw.");

    for (const auto& [type, window] : mWindows)
    {
        switch (type) 
        {
        case MAIN:
            if (WindowUtility::create_window(*window, window->get_width(), window->get_height())) 
            {
                mLogger->log(common::INFO, "[WindowManager][init] Successfully initialized main window.");
                WindowUtility::make_context_current(*window);
                WindowUtility::set_bg_color({ 0.05f, 0.06f, 0.06f, 1.0f });

                window->get_gui()->init();
                window->get_gui()->initWindowFields(window->get_win_ptr());
            } 
            else 
            {
                mLogger->log(common::FATAL, "[WindowManager][init] Error initializing main window.");
                glfwTerminate();
                return;
            }
            break;
        case INSPECTOR:
        case VIEW:
        case CONSOLE:
        default:
            break;
        }
    }
}
void WindowManager::loop()
{
    for (const auto& [type, window] : mWindows) 
    {
        while (WindowUtility::is_open(*window)) 
        {
            WindowUtility::poll_events();
            WindowUtility::color_bg();

            window->get_gui()->loop();

            WindowUtility::swap_buffers(*window);
        }
    }
}
void WindowManager::dispose()
{
    for (const auto& [type, window] : mWindows) 
    {
        if (WindowUtility::is_open(*window)) 
        {
            window->get_gui()->dispose();
            if (WindowUtility::destroy_window(*window)) 
            {
                mLogger->log(common::LogLevel::INFO, "[WindowManager][dispose] Destroyed window ", type, ".");
            } 
            else 
            {
                mLogger->log(common::LogLevel::ERROR, "[WindowManager][dispose] Could not destroy ", type, ".");
            }
        }
    }
    glfwTerminate();
    mLogger->log(common::INFO, "[WindowManager][dispose] Successfully closed window context.");
}

void WindowManager::addWindow(WindowType type, int32_t width, int32_t height)
{
    auto window = std::make_unique<Window>(width, height);

    switch (type) 
    {
        case MAIN:
            window->set_gui(std::make_unique<ui::MainGui>());
            mWindows.insert(std::pair<WindowType, std::unique_ptr<Window>>(type, std::move(window)));
            break;
        case INSPECTOR:
        case VIEW:
        case CONSOLE:
        default:
            break;
        }
}

void WindowManager::deleteWindow(WindowType type)
{
    mWindows.erase(type);
}
}