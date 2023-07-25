#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <map>

#include "logger.hpp"
#include "pipeline.hpp"
#include "window_utility.hpp"

namespace backend
{
enum WindowType
{
    MAIN, INSPECTOR, VIEW, CONSOLE
};
class WindowManager : CommonPipeline
{
public:
    void init() override; 
    void loop() override; 
    void draw() override; 
    void render() override;
    void dispose() override;

    void addWindow(WindowType type, int32_t width, int32_t height);
    void deleteWindow(WindowType type);
private:
    std::map<WindowType, std::unique_ptr<Window>> mWindows;
    std::shared_ptr<common::Logger> mLogger;
};
}

#endif