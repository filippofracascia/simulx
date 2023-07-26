#include "backend/engine/engine.hpp"
#include "common/logger.hpp"

int main()
{
    backend::Engine engine;
    engine.init();
    engine.loop();
    return 0;
}