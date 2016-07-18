#pragma once
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

class CONSTANTS{
public:
	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH = 800;
	static const int FPS_CAP = 60;
	static const int SCREEN_TICKS_PER_FRAME = 1000 / FPS_CAP;
	static const int JOYSTICK_DEAD_ZONE = 8000;

};
#endif