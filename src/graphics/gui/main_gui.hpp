#ifndef MAIN_GUI_HPP
#define MAIN_GUI_HPP

#include "graphics/gui/gui.hpp"

namespace ui 
{
class MainGui : public Gui
{
public:
    void loop() override;
};
}

#endif