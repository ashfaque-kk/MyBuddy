/********************************************************************
*   FILENAME       - CoreApiTypes.hpp
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
* @file        CoreApiTypes.hpp
* @ingroup     Interface
* @brief       Interface for application
* @author      Ashfaque
********************************************************************/

#ifndef _MY_BUDDY_API_TYPES_HPP__
#define _MY_BUDDY_API_TYPES_HPP__

//*************************************************
// Includes
//*************************************************
# include <iostream>
# include <stdint.h>

//*************************************************
// defines
//*************************************************

//*************************************************
// structure
//*************************************************

//*************************************************
// forward declarations
//*************************************************

namespace Mybuddy
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
    // width width of the window
    uint8_t width;
    // length length of the window
    uint8_t length;
    // x_axis x position of window relative to terminal screen
    uint8_t x_axis;
    // y_axis y position of window relative to terminal screen
    uint8_t y_axis;
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

} 
#endif // _MY_BUDDY_API_TYPES_HPP__