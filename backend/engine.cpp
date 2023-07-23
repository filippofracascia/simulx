#include <cstddef>
#include <iostream>
#include <memory>

#include "engine.hpp"
#include "logger.hpp"

using namespace backend;

void Engine::init()
{
    m_logger = common::Logger::getInstance();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
    });

    if(!glfwInit())
    {
        m_logger->log(common::FATAL, "Error initializing glfw.");
        return;
    }
    m_logger->log(common::INFO, "Successfully initialized glfw.");

    if((m_window = glfwCreateWindow(1920, 1080, "Simulator", NULL, NULL)) == NULL)
    {
        m_logger->log(common::FATAL, "Error initializing window.");
        glfwTerminate();
        return;
    }
    m_logger->log(common::INFO, "Successfully initialized window.");

    glfwMakeContextCurrent(m_window);
}

void Engine::loop()
{
    while(!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
}

void Engine::draw()
{
}

void Engine::render()
{
}

void Engine::dispose()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
    m_logger->log(common::INFO, "Closed application.");
}