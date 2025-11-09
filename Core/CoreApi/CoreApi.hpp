/********************************************************************
*   FILENAME       - CoreApi.hpp
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
* @file        CoreApi.hpp
* @ingroup     Interface
* @brief       Interface for application
* @author      Ashfaque
********************************************************************/

#ifndef _MY_BUDDY_CORE_API_HPP__
#define _MY_BUDDY_CORE_API_HPP__

//*************************************************
// Includes
//*************************************************
#include "CoreApiTypes.hpp"

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
class Window;
class MenuBar;
//*************************************************
// classes
//*************************************************
class CoreApi
{
public:
    CoreApi();
    ~CoreApi();
    
    void CreateMenuBar();
    void CreateWindow(WinParams param);
    void Draw();

private:
    Window* win;
    MenuBar* menu;

};

}       // namespace Mybuddy
#endif  // _MY_BUDDY_CORE_API_HPP__