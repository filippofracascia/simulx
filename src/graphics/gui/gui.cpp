#include "gui.hpp"
#include "imgui.h"

namespace ui 
{

void Gui::init()
{
    if(!initialized)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    #if defined(FONTS_DIR)
        const std::string FONTS = FONTS_DIR;
        mFiraSansLight = std::unique_ptr<ImFont>(io.Fonts->AddFontFromFileTTF((FONTS + "/fira_sans/FiraSans-Light.ttf").c_str(), 19.0f));
        mFiraSansRegular = std::unique_ptr<ImFont>(io.Fonts->AddFontFromFileTTF((FONTS + "/fira_sans/FiraSans-Regular.ttf").c_str(), 18.0f));
        mFiraSansMedium = std::unique_ptr<ImFont>(io.Fonts->AddFontFromFileTTF((FONTS + "/fira_sans/FiraSans-Medium.ttf").c_str(), 18.0f));
        mFiraSansBold = std::unique_ptr<ImFont>(io.Fonts->AddFontFromFileTTF((FONTS + "/fira_sans/FiraSans-Bold.ttf").c_str(), 18.0f));
    #endif

        ImGuiStyle* style = &ImGui::GetStyle();
    
        style->WindowPadding = ImVec2(12, 12);
        style->WindowRounding = 5.0f;
        style->FramePadding = ImVec2(5, 5);
        style->FrameRounding = 4.0f;
        style->ItemSpacing = ImVec2(10, 10);
        style->ItemInnerSpacing = ImVec2(8, 6);
        style->IndentSpacing = 25.0f;
        style->ScrollbarSize = 15.0f;
        style->ScrollbarRounding = 9.0f;
        style->GrabMinSize = 5.0f;
        style->GrabRounding = 3.0f;
    
        style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
        style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style->Colors[ImGuiCol_Border] = ImVec4(0.40f, 0.40f, 0.42f, 0.78f);
        style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
        style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
        style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);

        initialized = true;
        mLogger->log(common::INFO, "[Gui][init] Succesfully initialized gui.");
    }
}

void Gui::dispose()
{
    if(!destroyed)
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        destroyed = true;
        mLogger->log(common::INFO, "[Gui][dispose] Succesfully disposed gui.");
    }
}

void Gui::initWindowFields(GLFWwindow* window)
{
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
}
} // namespace ui