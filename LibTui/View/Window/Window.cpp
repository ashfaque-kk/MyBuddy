/********************************************************************
*   FILENAME       - Window.cpp
*********************************************************************
*   CHANGE HISTORY
*   -----------------------------------------------------------------
*   DATE           REVISION      AUTHOR             COMMENTS
*   -----------------------------------------------------------------
*   Nov/09/25      0.01          Ashfaque         Initial version  
*********************************************************************
*  File Description
*  ---------------------
*  This file provide Impelemetation to MenuBar class
********************************************************************
* @file        Window.cpp
* @ingroup     UI Components
* @brief       Impelemetation
* @author      Ashfaque
********************************************************************/


//*************************************************
// Includes
//*************************************************
#include "Window.hpp"

using namespace TUI;

Window::Window()
: mWin(nullptr)
{
}

Window::~Window()
{
   
}

void Window::CreateWindow(WinParams param)
{
    // int height, width;
    // getmaxyx(stdscr, height, width);
    // check TBD
    
    WINDOW* mWin   = newwin(param.length - 5, param.width, 3, 0);
    (void) mWin;
}

void Window::DrawWindow(const std::vector<std::string>& tasks)
{
    werase(mWin);
    box(mWin, 0, 0);
    mvwprintw(mWin, 0, 2, " Tasks ");
    for (size_t i = 0; i < tasks.size(); ++i) {
        mvwprintw(mWin, i + 1, 2, "[%zu] %s", i + 1, tasks[i].c_str());
    }
    wrefresh(mWin);
}
