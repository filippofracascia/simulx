#include <cstddef>
#include <iostream>
#include <memory>

#include "engine.hpp"
#include "logger.hpp"
#include "window_manager.hpp"

using namespace backend;

void Engine::init()
{
    WindowUtility::set_log_callback();
    
    mWindowManager.addWindow(WindowType::MAIN, 1920, 1080);
    mWindowManager.init();
}

void Engine::loop()
{
    mWindowManager.loop();
}

void Engine::draw()
{
}

void Engine::render()
{
}

void Engine::dispose()
{
    mWindowManager.dispose();
    mLogger->log(common::INFO, "[Engine][dispose] Closed application.");
}