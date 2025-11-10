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
            mWin->DrawWindow(vd.data);
        }
        break;
    case View::TUI_MENUBAR:
        {
            mMenu->DrawMenuBar(vd.data,0);
        }
        break;
    
    default:
        break;
    }
}

