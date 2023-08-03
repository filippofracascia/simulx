#ifndef GL_SHADER_HPP
#define GL_SHADER_HPP

#include <memory>
#include <string>

#include "common/logger.hpp"
#include "graphics/shader/shader.hpp"

namespace graphics 
{
class GlShader : Shader 
{
public:
    GlShader(const std::string& vertexPath, const std::string& fragmentPath);
    ~GlShader() = default;

    void use() override;

    const unsigned int getID() const noexcept;

private:
    void checkCompileErrors(unsigned int shader, const std::string& type);

    unsigned int mID;
    std::shared_ptr<common::Logger> mLogger;
};
}

#endif