#include "main_gui.hpp"

namespace ui
{

void MainGui::loop()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (mFiraSansRegular != nullptr) 
    {
        ImGui::PushFont(mFiraSansRegular.get());
    }

    if (ImGui::BeginMainMenuBar()) 
    {
        if (ImGui::BeginMenu("File")) 
        {
            ImGui::MenuItem("Open");
            ImGui::MenuItem("Save");
            ImGui::MenuItem("Exit");
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) 
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Tools")) 
        {
            ImGui::EndMenu();
        }

        ImGui::PopFont();
        ImGui::EndMainMenuBar();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
}