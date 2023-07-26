#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "gl_context.hpp"

namespace backend
{
void GlContext::init()
{
    initGl();
}
void GlContext::loop()
{

}
void GlContext::dispose()
{

}

void GlContext::initGl()
{
    if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) != 0)
    {
        mLogger->log(common::INFO, "[GlContext][linkGladLoader] Successfully linked glad loader for OpenGL.");
    }
    else 
    {
        mLogger->log(common::ERROR, "[GlContext][linkGladLoader] Could not link glad loader for OpenGL.");
    }
}

void GlContext::initShaders()
{

}
}