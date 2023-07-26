#ifndef GL_CONTEXT_HPP
#define GL_CONTEXT_HPP

#include <memory>

#include "backend_context.hpp"
#include "common/logger.hpp"

namespace backend {
class GlContext : BackendContext {
public:
    void init() override;
    void loop() override;
    // void draw() override;
    // void render() override;
    void dispose() override;

    void initShaders() override;

private:
    void initGl();

    std::shared_ptr<common::Logger> mLogger;
};
}

#endif