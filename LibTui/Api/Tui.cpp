/********************************************************************
*   FILENAME       - Tui.cpp
*********************************************************************
*   CHANGE HISTORY
*   -----------------------------------------------------------------
*   DATE           REVISION      AUTHOR             COMMENTS
*   -----------------------------------------------------------------
*   Nov/10/25      0.01          Ashfaque         Initial version  
*********************************************************************
*  File Description
*  ---------------------
*  This file provide implementation for Core api's
********************************************************************
* @file        Tui.cpp
* @ingroup     Interface
* @brief       implementation
* @author      Ashfaque
********************************************************************/

//*************************************************
// Includes
//*************************************************
#include "Tui.hpp"
#include "Window.hpp"
#include "MenuBar.hpp"

using namespace TUI;

Tui::Tui()
: mWin(nullptr),
  mMenu(nullptr)
{
    mWin  = new Window();
    mMenu = new MenuBar();
}

Tui::~Tui()
{
    delete mWin;
    delete mMenu;
}

void Tui::Init()
{
    initscr();              // Initialize ncurses
    cbreak();               // Disable line buffering
    noecho();               // Don't echo keys
    keypad(stdscr, TRUE);   // Enable function/arrow keys
    curs_set(0);            // Hide cursor
    start_color();          // Enable colors
    use_default_colors();
    refresh();
    // Enable mouse events
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    // Start UI thread
    mUIthread = std::thread(&Tui::TuiService, this);
}

void Tui::Terminate()
{
    endwin();  // Restore normal terminal
}

void Tui::CreateMenuBar(MenuParams param)
{
    mMenu->CreateMenuBar(param);
}

void Tui::CreateWindow(WinParams param)
{
    mWin->CreateWindow(param);
}

void Tui::Draw(IViewData vd)
{
    switch (vd.view)
    {
    case View::TUI_WINDOW:
        {
            mViewDataWin = vd;
            mWin->DrawWindow(vd.data);
        }
        break;
    case View::TUI_MENUBAR:
        {
            mViewDataMenu = vd;
            mMenu->DrawMenuBar(vd.data,mHighlight);
        }
        break;
    
    default:
        break;
    }
}

void Tui::GetTerminalSize(uint8_t& height, uint8_t& width)
{
    getmaxyx(stdscr, height, width);
}

void Tui::TuiService()
{
    pthread_setname_np(pthread_self(), "UIthread");
    MEVENT event;
    int ch;;
    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_LEFT:
                mHighlight = (mHighlight == 0) ? mViewDataMenu.data.size() - 1 : mHighlight - 1;
                break;
            case KEY_RIGHT:
                mHighlight = (mHighlight + 1) % mViewDataMenu.data.size();
                break;
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    // Only react to mouse left click
                    if (event.bstate & BUTTON1_CLICKED) {
                        // Check if click is in menu window's height (y=0,1,2)
                        if (event.y >= 1 && event.y <= 1) {
                            int clicked_index = GetMenuIndexAt(event.x, mViewDataMenu.data);
                            if (clicked_index != -1) 
                            {
                                mHighlight = clicked_index;
                            }
                        }
                    }
                }
                break;
            case 10: // Enter key
                // Handle menu selection

                break;
        }
        Draw(mViewDataMenu);
        Draw(mViewDataWin);
    }
}

// Helper function to find menu item clicked by mouse
int Tui::GetMenuIndexAt(int mouse_x, const std::vector<std::string>& menus) 
{
    int x = 2;
    for (size_t i = 0; i < menus.size(); ++i) {
        int start_x = x;
        int end_x = x + (int)menus[i].size() - 1;
        if (mouse_x >= start_x && mouse_x <= end_x) {
            return i;
        }
        x += menus[i].size() + 6;
    }
    return -1;  // no menu clicked
}