#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <SDL.h>
#include <iostream>

class Renderer
{
public:
	static Renderer* instance();

#define SceneRenderer Renderer::instance()->getRenderer()

	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH = 1200;
	
	void close();
	SDL_Renderer* getRenderer();
private:
	Renderer();
	~Renderer();
	static Renderer* m_instance;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};

#endif