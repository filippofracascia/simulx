#ifndef GUI_HPP
#define GUI_HPP

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <memory>

#include "common/logger.hpp"
#include "graphics/window/window.hpp"
#include "common/pipeline.hpp"

namespace graphics {
class Gui : CommonPipeline
{
public:
    void init() override;
    void loop() override;
    void dispose() override;

    void initWindowFields(const graphics::Window& window);
    void updateWindowFields(const graphics::Window& window);

private:
    int32_t mWindowWidth;
    int32_t mWindowHeight;

    std::shared_ptr<common::Logger> mLogger;
};
}

#endif