/********************************************************************
*   FILENAME       - Tui.hpp
*********************************************************************
*   CHANGE HISTORY
*   -----------------------------------------------------------------
*   DATE           REVISION      AUTHOR             COMMENTS
*   -----------------------------------------------------------------
*   Nov/10/25      0.01          Ashfaque         Initial version  
*********************************************************************
*  File Description
*  ---------------------
*  This file provide interface to tui library
********************************************************************
* @file        Tui.hpp
* @ingroup     Interface
* @brief       Interface for application
* @author      Ashfaque
********************************************************************/

#ifndef _TUI_HPP__
#define _TUI_HPP__

//*************************************************
// Includes
//*************************************************
#include "TuiTypes.hpp"

#include <thread>

//*************************************************
// defines
//*************************************************

//*************************************************
// structure
//*************************************************

//*************************************************
// forward declarations
//*************************************************

namespace TUI
{
class Window;
class MenuBar;
//*************************************************
// classes
//*************************************************
class Tui
{
public:
    Tui();
    ~Tui();

    // Initialize and Terminate TUI
    void Init();
    void Terminate();
    // Create Views
    void CreateMenuBar(MenuParams param);
    void CreateWindow(WinParams param);
    // Draw Views
    void Draw(IViewData vd);
    //UI Thread
    void TuiService();
    // Utils
    void GetTerminalSize(uint8_t& height, uint8_t& width);
    int GetMenuIndexAt(int mouse_x, const std::vector<std::string>& menus);

private:
    // View Components
    Window* mWin;
    MenuBar* mMenu;
    uint8_t mHighlight = 0;
    // View Data
    IViewData mViewDataWin;
    IViewData mViewDataMenu;
    
    std::thread mUIthread;
};

}       // namespace TUI
#endif  // _TUI_HPP__