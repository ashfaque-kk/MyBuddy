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

using namespace Mybuddy;

Window::Window()
{
    // Constructor implementation
}
Window::~Window()
{
    // Destructor implementation
}

void Window::CreateWindow()
{
    // Method to create window
}
void Window::DrawWindow(WINDOW* task_win, const std::vector<std::string>& tasks)
{
    werase(task_win);
    box(task_win, 0, 0);
    mvwprintw(task_win, 0, 2, " Tasks ");
    for (size_t i = 0; i < tasks.size(); ++i) {
        mvwprintw(task_win, i + 1, 2, "[%zu] %s", i + 1, tasks[i].c_str());
    }
    wrefresh(task_win);
}
