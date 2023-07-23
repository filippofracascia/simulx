#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <memory>
#include <mutex>
#include <string>

#define stringify( name ) #name

namespace common
{

enum LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

inline const std::string log_level_to_string[] =
{
    stringify(DEBUG),
    stringify(INFO),
    stringify(WARNING),
    stringify(ERROR),
    stringify(FATAL),
};

inline const std::string level_to_string(LogLevel level)
{
    return log_level_to_string[level];
}

class Logger
{
private:
    Logger();
    inline static std::shared_ptr<Logger> logger;
    inline static std::once_flag initInstanceFlag;
public:
    Logger(const Logger&)=delete;
    auto& operator =(const Logger&)=delete;

    static std::shared_ptr<Logger>& getInstance();
    void log(LogLevel logLevel, const std::string& message);
};
}

#endif