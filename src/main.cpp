#include "common/logger.hpp"
#include "graphics/engine/engine.hpp"

int main()
{
    graphics::Engine engine;
    engine.init();
    engine.loop();
    return 0;
}