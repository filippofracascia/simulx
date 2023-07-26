#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <map>

#include "common/logger.hpp"
#include "common/pipeline.hpp"
#include "backend/window/window_utility.hpp"

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
    //void draw() override; 
    //void render() override;
    void dispose() override;

    void addWindow(WindowType type, int32_t width, int32_t height);
    void deleteWindow(WindowType type);
private:
    std::map<WindowType, std::unique_ptr<Window>> mWindows;
    std::shared_ptr<common::Logger> mLogger;
};
}

#endif