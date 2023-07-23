#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "pipeline.hpp"
#include "logger.hpp"

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
        GLFWwindow* m_window;
        uint32_t m_width;
        uint32_t m_height;

        std::shared_ptr<common::Logger> m_logger;
    };
}

#endif