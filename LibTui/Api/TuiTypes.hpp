/********************************************************************
*   FILENAME       - TuiTypes.hpp
*********************************************************************
*   CHANGE HISTORY
*   -----------------------------------------------------------------
*   DATE           REVISION      AUTHOR             COMMENTS
*   -----------------------------------------------------------------
*   Nov/10/25      0.01          Ashfaque         Initial version  
*********************************************************************
*  File Description
*  ---------------------
*  This file provide interface to core api's
********************************************************************
* @file        TuiTypes.hpp
* @ingroup     Interface
* @brief       Interface for application
* @author      Ashfaque
********************************************************************/

#ifndef _TUI_TYPES_HPP__
#define _TUI_TYPES_HPP__

//*************************************************
// Includes
//*************************************************
#include <iostream>
#include <stdint.h>
#include <vector>

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

/**
 * @brief Status of a function or method call
 * 
 * This enumerate describes the status of a call.
 */
enum class Status: uint8_t
{
    TUI_STATUS_SUCCESS = 0,             // Call is successful
    TUI_STATUS_FAILED = 1,              // Call is failed
    TUI_STATUS_INVALID_PARAMS = 2,      // Bad input parameter is provided
    TUI_STATUS_UNKNOWN = 3,             // Unknown status. This should never happen. 
    TUI_STATUS_MAX
};

enum class View: uint8_t
{
    TUI_WINDOW = 1,
    TUI_MENUBAR = 2,
    TUI_VIEW_MAX
};

/*******************************************************************************
    WINDOW* win = newwin(width , length, x_axis, y_axis):
                    x_axis
            (0,0) ________________________________
                |                
                |                length
                |            ________________
       y_axis   |           |                |
                |    width  |                |
                |           |                |
                |           |________________|
                |
                |
                |
*******************************************************************************/

//! \brief This structure used to pass window parameters
struct WinParams
{
    // Window id
    uint8_t id;
    // Window Name
    std::string text;
    // length length of the window
    size_t length;
    // width width of the window
    size_t width;
    // x_axis x position of window relative to terminal screen
    size_t x_axis;
    // y_axis y position of window relative to terminal screen
    size_t y_axis;

    // WinParams()
    // :id(0),text(""),length(0),width(0),x_axis(0),y_axis(0)
    // {}
};

struct MenuParams
{
    // length length of the window
    size_t length;
    // width width of the window
    size_t width;
    // x_axis x position of window relative to terminal screen
    size_t x_axis;
    // y_axis y position of window relative to terminal screen
    size_t y_axis;
    // menu items
    std::vector<std::string> menus;
};

//! \brief This structure used to pass menu item details
// struct MenuItem {
//     uint8_t id;
//     std::string text;
//     // Function to be executed when the menu item is selected
//     std::function<void()> action;
//     // Sub-menu items, if any
//     std::vector<MenuItem> subMenu;
// };

//! \brief This structure used to pass button details
// struct Button {
//     uint8_t id;
//     std::string text;
//     // Function to be executed when the button item is selected
//     std::function<void()> action;
// };

struct IViewData
{
    View view;
    std::vector<std::string> data;
};

} 
#endif // _TUI_TYPES_HPP__