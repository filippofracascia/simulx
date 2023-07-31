#include <cstddef>
#include <iostream>
#include <memory>

#include "graphics/shader/gl_shader.hpp"
#include "common/logger.hpp"
#include "engine.hpp"

namespace graphics {

Engine::Engine()
{
}

void Engine::init()
{
    WindowUtility::set_log_callback();

    mWindowManager.addWindow(WindowType::MAIN, 1920, 1080);
    mWindowManager.init();

    mGraphicsContext.init();

#if defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == OPENGL && defined (SHADERS_DIR)
    const std::string SHADERS = SHADERS_DIR;
    mShader = std::make_unique<GlShader>(SHADERS + "/default.vert", SHADERS + "/default.frag");
#elif defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == VULKAN
        mShader = std::make_unique<VkShader>("../shader", "../Shader");
#elif defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == METAL
        mShader = std::make_unique<MtShader>("../shader", "../Shader");
#endif
}

void Engine::loop() { mWindowManager.loop(); }

void Engine::dispose()
{
    mWindowManager.dispose();
    mLogger->log(common::INFO, "[Engine][dispose] Closed application.");
}
} // namespace graphics