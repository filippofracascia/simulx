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
    /**
     * @brief Initialize the object and prepare it for the pipeline
     * 
     */
    virtual void init() = 0;
    /**
     * @brief Update the object every new pipeline cycle
     * 
     */
    virtual void loop() = 0;
    /**
     * @brief Dispose the object from the pipeline
     * 
     */
    virtual void dispose() = 0;
};

#endif