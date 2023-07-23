#ifndef COMMOMPIPELINE_HPP
#define COMMOMPIPELINE_HPP

class CommonPipeline
{
protected:
    virtual void init() = 0;
    virtual void loop() = 0;
    virtual void draw() = 0;
    virtual void render() = 0;
    virtual void dispose() = 0;
};

#endif