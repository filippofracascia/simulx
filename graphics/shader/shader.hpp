#ifndef SHADER_HPP
#define SHADER_HPP

namespace graphics
{
class Shader
{
public:
    ~Shader()=default;
    virtual void use() = 0;
};
}

#endif