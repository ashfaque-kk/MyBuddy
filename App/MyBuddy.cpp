#include "Tui.hpp"
#include <string>
#include <vector>

using namespace TUI;


int main() {
    
    // Initialize TUI
    Tui mTui;
    mTui.Init();

    // Get terminal size
    uint8_t height, width;
    mTui.GetTerminalSize(height, width);

    // Create Menubar
    std::vector<std::string> menus = {"File", "Edit", "Help"};
    MenuParams menuparam = {3, width, 0, 0, menus};
    mTui.CreateMenuBar(menuparam);
    
    // Create window sizes
    WinParams winparam = {1,"task_win",(height - 5U), width, 3, 0};
    mTui.CreateWindow(winparam);

    // Draw Menubar
    IViewData vdmenu;
    vdmenu.view = View::TUI_MENUBAR;
    vdmenu.data = menus;
    mTui.Draw(vdmenu);

    // Tasks
    std::vector<std::string> tasks = {
        "Finish project report (Due: 2025-11-10)",
        "Pay electricity bill (Due: 2025-11-08)",
        "Schedule dentist appointment"
    };
    // Draw Window
    IViewData vdwin;
    vdwin.view = View::TUI_WINDOW;
    vdwin.data = tasks;
    mTui.Draw(vdwin);
    
    // Main loop
    while (true) 
    {
        // Wait for user input
        // Take user actions and do something
    }

    mTui.Terminate();
    return 0;
}