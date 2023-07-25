#include "window_manager.hpp"
#include "GLFW/glfw3.h"
#include "logger.hpp"
#include "window.hpp"
#include "window_utility.hpp"
#include <cstdint>
#include <memory>

using namespace backend;

void WindowManager::init()
{
    mLogger = common::Logger::getInstance();

    if(!glfwInit())
    {
        mLogger->log(common::FATAL, "[WindowManager][init] Error initializing glfw.");
        return;
    }
    mLogger->log(common::INFO, "[WindowManager][init] Successfully initialized glfw.");

    for (auto& window : mWindows) 
    {
        switch(window.first)
        {
        case MAIN: 
            if(WindowUtility::create_window(*window.second, *window.second->get_width_ptr(), *window.second->get_height_ptr()))
            {
                mLogger->log(common::INFO, "[WindowManager][init] Successfully initialized main window.");
                WindowUtility::make_context_current(*window.second);
                glClearColor(0.1f, 0.2f, 0.1f, 1.0f);
            }
            else
            {
                mLogger->log(common::FATAL, "[WindowManager][init] Error initializing main window.");
                glfwTerminate();
                return;
            }
            break;
        case INSPECTOR: break;
        case VIEW: break;
        case CONSOLE: break;
        default: break;
        }
    }
}
void WindowManager::loop()
{
    for (auto& window : mWindows) {
        while(WindowUtility::is_open(*window.second))
        {
            WindowUtility::poll_events();
            WindowUtility::swap_buffers(*window.second);
        }
    }
}
void WindowManager::draw()
{
}
void WindowManager::render()
{
}
void WindowManager::dispose()
{
    for (auto& window : mWindows) 
    {
        if(WindowUtility::is_open(*window.second))
        {
            if(WindowUtility::destroy_window(*window.second))
            {
                mLogger->log(common::LogLevel::INFO, "[WindowManager][dispose] Destroyed window ", window.first, ".");
            }
            else 
            {
                mLogger->log(common::LogLevel::ERROR, "[WindowManager][dispose] Could not destroy ", window.first, ".");
            }
        }
    }
    glfwTerminate();
    mLogger->log(common::INFO, "[WindowManager][dispose] Successfully closed window context.");
}

void WindowManager::addWindow(WindowType type, int32_t width, int32_t height)
{
    mWindows.insert(std::pair<WindowType, std::unique_ptr<Window>>(type, std::make_unique<Window>(width, height)));
}

void WindowManager::deleteWindow(WindowType type)
{
    mWindows.erase(type);
}