#ifndef GUI_HPP
#define GUI_HPP

#include <imgui.h>
#include <memory>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "common/logger.hpp"
#include "common/pipeline.hpp"

// @todo: set interface to call imgui functions with nullptr checks

namespace ui
{
class Gui : CommonPipeline 
{
public:

    ~Gui()=default;

    /**
     * @brief Defines the common style and fonts components for the whole ui,
     * can be further overridden by ui implementations.
     * 
     */
    virtual void init() override;

    /**
     * @brief In loop we actually define the components for the window ui, so it must be implemented
     * by each ui singularly.
     * 
     */
    virtual void loop() override = 0;

    /**
     * @brief Disposes the whole ui component, can be further overridden by ui implementations.
     * 
     */
    virtual void dispose() override;

    /**
     * @brief 
     * 
     * @param window 
     */
    virtual void initWindowFields(GLFWwindow* window);

protected:

    std::unique_ptr<ImFont> mFiraSansLight;
    std::unique_ptr<ImFont> mFiraSansRegular;
    std::unique_ptr<ImFont> mFiraSansMedium;
    std::unique_ptr<ImFont> mFiraSansBold;

    std::shared_ptr<common::Logger> mLogger;

private:
    bool initialized = false;
    bool destroyed = false;
};
}

#endif