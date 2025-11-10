/********************************************************************
*   FILENAME       - MenuBar.cpp
*********************************************************************
*   CHANGE HISTORY
*   -----------------------------------------------------------------
*   DATE           REVISION      AUTHOR             COMMENTS
*   -----------------------------------------------------------------
*   Nov/09/25      0.01          Ashfaque         Initial version  
*********************************************************************
*  File Description
*  ---------------------
*  This file provide implementation to MenuBar class
********************************************************************
* @file        MenuBar.cpp
* @ingroup     UI Components
* @brief       implementation
* @author      Ashfaque
********************************************************************/

//*************************************************
// Includes
//*************************************************
#include "MenuBar.hpp"

using namespace TUI;

MenuBar::MenuBar()
: mMenu(nullptr)
{
    // Constructor implementation
}

MenuBar::~MenuBar()
{
    // Destructor implementation
}

void MenuBar::CreateMenuBar(MenuParams param)
{
    WINDOW* mMenu = newwin(param.length, param.width, 0, 0);
    (void) mMenu;
}

void MenuBar::DrawMenuBar(const std::vector<std::string>& menus, int highlight) 
{
    werase(mMenu);
    box(mMenu, 0, 0);
    int x = 2;
    for (size_t i = 0; i < menus.size(); ++i) {
        if ((int)i == highlight)
            wattron(mMenu, A_REVERSE);
        mvwprintw(mMenu, 1, x, "%s", menus[i].c_str());
        wattroff(mMenu, A_REVERSE);
        x += menus[i].size() + 6;
    }
    wrefresh(mMenu);
}