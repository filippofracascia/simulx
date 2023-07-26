#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>

#include "backend/manager/window_manager.hpp"
#include "common/logger.hpp"
#include "common/pipeline.hpp"

#if defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == OPENGL
#include "backend/context/gl_context.hpp"
#elif defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == VULKAN
#include "backend/context/vk_context.hpp"
#elif defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == METAL
#include "backend/context/mt_context.hpp"
#endif

namespace backend {
class Engine : CommonPipeline {
public:
    Engine();

    void init() override;
    void loop() override;
    // void draw() override;
    // void render() override;
    void dispose() override;

private:
    std::shared_ptr<common::Logger> mLogger;
    WindowManager mWindowManager;
#if defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == OPENGL
    std::unique_ptr<GlContext> mBackendContext;
#elif defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == VULKAN
    std::unique_ptr<VkContext> mBackendContext;
#elif defined(BACKEND_CONTEXT) && BACKEND_CONTEXT == METAL
    std::unique_ptr<MtContext> mBackendContext;
#endif
};
} // namespace backend

#endif