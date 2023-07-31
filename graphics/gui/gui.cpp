#include "gui.hpp"
#include "imgui.h"

namespace graphics
{

void Gui::init()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    //ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();
}

void Gui::loop() 
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if(ImGui::BeginMainMenuBar())
    {
        if(ImGui::BeginMenu("File"))
        {
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Edit"))
        {
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Tools"))
        {
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Gui::dispose()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    mLogger->log(common::INFO, "[Gui][dispose] Closed gui.");
}

void Gui::initWindowFields(const graphics::Window& window)
{
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window.get_win_ptr(), true);
    ImGui_ImplOpenGL3_Init("#version 460");
}

void Gui::updateWindowFields(const graphics::Window& window)
{
    //mWindowWidth = window.get_width();
    //mWindowHeight = window.get_height();
}
} // namespace graphics