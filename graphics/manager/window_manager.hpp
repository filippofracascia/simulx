#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <map>

#include "graphics/window/window_utility.hpp"
#include "graphics/gui/gui.hpp"
#include "common/logger.hpp"
#include "common/pipeline.hpp"

namespace graphics {

/**
 * @brief The unique type of the window
 * 
 */
enum WindowType {
    MAIN,
    INSPECTOR,
    VIEW,
    CONSOLE
};

/**
 * @brief Container for windows.
 * It's responsable for the life of the windows
 * 
 */
class WindowManager : CommonPipeline {
public:
    void init() override;
    void loop() override;
    void dispose() override;

    /**
     * @brief Add a window to the pipeline
     * 
     * @param type the type of the window
     * @param width the width of the window
     * @param height the height of the window
     */
    void addWindow(WindowType type, int32_t width, int32_t height);

    /**
     * @brief Deletes a window from the pipeline
     * 
     * @param type the type of the window to delete
     */
    void deleteWindow(WindowType type);

private:
    std::map<WindowType, std::unique_ptr<Window>> mWindows;
    Gui mGui;

    std::shared_ptr<common::Logger> mLogger;
};
}

#endif