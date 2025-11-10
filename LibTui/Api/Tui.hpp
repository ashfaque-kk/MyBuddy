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
    
    void CreateMenuBar(MenuParams param);
    void CreateWindow(WinParams param);
    void Draw(IViewData vd);

private:
    Window* mWin;
    MenuBar* mMenu;
};

}       // namespace TUI
#endif  // _TUI_HPP__