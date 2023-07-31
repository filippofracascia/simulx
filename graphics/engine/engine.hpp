#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>

#include "graphics/gui/gui.hpp"
#include "graphics/manager/window_manager.hpp"
#include "common/logger.hpp"
#include "common/pipeline.hpp"

#if defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == OPENGL
#include "graphics/context/gl_context.hpp"
#include "graphics/shader/gl_shader.hpp"
#elif defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == VULKAN
#include "graphics/context/vk_context.hpp"
#include "graphics/shader/vk_shader.hpp"
#elif defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == METAL
#include "graphics/context/mt_context.hpp"
#include "graphics/shader/mt_shader.hpp"
#endif

namespace graphics {
class Engine : CommonPipeline {
public:
    Engine();

    void init() override;
    void loop() override;
    void dispose() override;

private:
    std::shared_ptr<common::Logger> mLogger;
    WindowManager mWindowManager;

#if defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == OPENGL
    GlContext mGraphicsContext;
    std::unique_ptr<GlShader> mShader;
#elif defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == VULKAN
    VkContext mGraphicsContext;
    VkShader mShader;
#elif defined(GRAPHICS_CONTEXT) && GRAPHICS_CONTEXT == METAL
    MtContext mGraphicsContext;
    MtShader mShader;
#endif
};
} // namespace graphics

#endif