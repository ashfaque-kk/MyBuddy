/********************************************************************
*   FILENAME       - MenuBar.hpp
*********************************************************************
*   CHANGE HISTORY
*   -----------------------------------------------------------------
*   DATE           REVISION      AUTHOR             COMMENTS
*   -----------------------------------------------------------------
*   Nov/09/25      0.01          Ashfaque         Initial version  
*********************************************************************
*  File Description
*  ---------------------
*  This file provide interface to MenuBar class
********************************************************************
* @file        MenuBar.hpp
* @ingroup     UI Components
* @brief       Interface
* @author      Ashfaque
********************************************************************/

#ifndef _TUI_MENU_BAR_HPP__
#define _TUI_MENU_BAR_HPP__

//*************************************************
// Includes
//*************************************************
#include "Common.hpp"
//*************************************************
// defines
//*************************************************

//*************************************************
// forward declarations
//*************************************************

namespace TUI
{

//*************************************************
// classes
//*************************************************
class MenuBar
{
public:
    MenuBar();
    ~MenuBar();
    
    void CreateMenuBar(MenuParams param);
    void DrawMenuBar(const std::vector<std::string>& menus, int highlight);

private:
    WINDOW* mMenu;

};

}       // namespace TUI
#endif  // _TUI_MENU_BAR_HPP__