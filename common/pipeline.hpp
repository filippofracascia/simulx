#ifndef PIPELINE_HPP
#define PIPELINE_HPP

/**
 * @brief The base interface for each pipeline object
 *
 * Each object must inherit from \interface CommonPipeline to work within the engine lifecycle.
 */
class CommonPipeline {
public:
    virtual ~CommonPipeline() = default;

protected:
    virtual void init() = 0;
    virtual void loop() = 0;
    virtual void dispose() = 0;
};

#endif