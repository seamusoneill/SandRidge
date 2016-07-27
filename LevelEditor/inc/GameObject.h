#pragma once
#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

/*The representation of our game object which will be placed on the map.*/

#include <SDL.h>
#include <string>

class GameObject{
public: //Todo make private or use the struct
	SDL_Texture* mTexture;
	std::string mId;
};

/*
struct GameObject{
	SDL_Texture* mTexture;
	std::string mId;
};
*/

#endif // !_GAME_OBJECT_H_
