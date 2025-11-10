/********************************************************************
*   FILENAME       - Window.hpp
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
* @file        Window.hpp
* @ingroup     UI Components
* @brief       Interface
* @author      Ashfaque
********************************************************************/

#ifndef _TUI_WINDOW_HPP__
#define _TUI_WINDOW_HPP__

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
class Window
{
public:
    Window();
    ~Window();
    
    void CreateWindow(WinParams param);
    void DrawWindow(const std::vector<std::string>& tasks);

private:
    WINDOW* mWin;

};

}       // namespace Mybuddy
#endif  // _TUI_WINDOW_HPP__