#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "pipeline.hpp"
#include "logger.hpp"
#include "window_manager.hpp"

namespace backend
{
class Engine : CommonPipeline
{
public:
    void init() override;
    void loop() override;
    void draw() override;
    void render() override;
    void dispose() override;

private:
    WindowManager mWindowManager;
    std::shared_ptr<common::Logger> mLogger;
};
}

#endif