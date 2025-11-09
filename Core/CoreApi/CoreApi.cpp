/********************************************************************
*   FILENAME       - CoreApi.cpp
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
* @file        CoreApi.cpp
* @ingroup     Interface
* @brief       implementation
* @author      Ashfaque
********************************************************************/

//*************************************************
// Includes
//*************************************************
#include "CoreApi.hpp"
#include "Window.hpp"
#include "MenuBar.hpp"

using namespace Mybuddy;

CoreApi::CoreApi()
: win(nullptr),
  menu(nullptr)
{
    win  = new Window();
    menu = new MenuBar();
}

CoreApi::~CoreApi()
{
    delete win;
    delete menu;
}

void CoreApi::CreateMenuBar()
{
    // Method to create menu bar
}

