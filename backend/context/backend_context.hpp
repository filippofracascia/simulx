#ifndef BACKEND_CONTEXT_HPP
#define BACKEND_CONTEXT_HPP

#include "common/pipeline.hpp"

namespace backend {

/**
 * @brief \class BackendContext is the base class for a 3D context
 *
 * Each backend must inherit from \class BackendContext.
 *
 * \par Backends implemented:
 *
 * - [x] OpenGL
 * - [ ] Vulkan
 * - [ ] Metal
 *
 */
class BackendContext : CommonPipeline {
public:
    virtual ~BackendContext() = default;

    virtual void init() override = 0;
    virtual void loop() override = 0;
    // void draw() override;
    // void render() override;
    virtual void dispose() override = 0;

    /**
     * @brief Initialize shaders for current context.
     *
     */
    virtual void initShaders() = 0;
};
} // namespace backend

#endif