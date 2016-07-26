#pragma once
#ifndef _MAP_WINDOW_H_
#define _MAP_WINDOW_H_

/* Class which holds the empty map to be populated with obects.
* Responsibilities are: Drawing a tile grid which matches the one used in the game,
* Placing a selected object in the correct tile upon click,
* Holding a list of chars which will be written to an external file when the save button is pressed.*/

#include "MenuWindow.h"

class MapWindow : MenuWindow
{

};
#endif //!_MAP_WINDOW_H_