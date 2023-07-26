#include <cstddef>
#include <iostream>
#include <memory>

#include "engine.hpp"

namespace backend {

Engine::Engine() {
#if defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == OPENGL
    mBackendContext = std::make_unique<GlContext>();
#elif defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == VULKAN
    mBackendContext = std::make_unique<VkContext>();
#elif defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == METAL
    mBackendContext = std::make_unique<MtContext>();
#endif
}

void Engine::init() {
    WindowUtility::set_log_callback();

    mWindowManager.addWindow(WindowType::MAIN, 1920, 1080);
    mWindowManager.init();

    mBackendContext->init();
}

void Engine::loop() { mWindowManager.loop(); }

/*void Engine::draw()
{
}

void Engine::render()
{
}*/

void Engine::dispose() {
    mWindowManager.dispose();
    mLogger->log(common::INFO, "[Engine][dispose] Closed application.");
}
} // namespace backend