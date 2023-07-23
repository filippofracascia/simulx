#include "logger.hpp"
#include <iostream>
#include <memory>

namespace common
{
Logger::Logger()
{
}

std::shared_ptr<Logger>& Logger::getInstance()
{
    if(logger == nullptr)
    {
        std::call_once(initInstanceFlag, [] {
        logger.reset(new Logger);
    });
    }
    return logger;
}

void Logger::log(LogLevel logLevel, const std::string &message)
{
    std::cout << level_to_string(logLevel) << ":" << message << std::endl;
}
}