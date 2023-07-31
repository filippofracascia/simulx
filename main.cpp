#include "graphics/engine/engine.hpp"
#include "common/logger.hpp"

int main()
{
    graphics::Engine engine;
    engine.init();
    engine.loop();
    return 0;
}