#pragma once
#ifndef _FONT_TEXTURE_H_
#define _FONT_TEXTURE_H_

#include <string>
#include <SDL_ttf.h>
#include "Renderer.h"
class FontTexture
{
public:
	FontTexture();
	~FontTexture();
	
	//Deallocates texture
	void free();

	//Takes font and string and produces a texture
	bool loadFromFile(std::string text, std::string path = "res/font/default.ttf",  int size = 20, SDL_Color color = { 0, 0, 0 });

	//Render texture at given point
	void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Change the font by replacing the texture and passing in a new path
	void setFont(std::string path);

	//Change the text by replacing the old texture
	void setText(std::string text);
	
	//Set color by replacing the texture
	void setColor(SDL_Color color);

	//Set font size by replacing the texture
	void setFontSize(int size);
	
	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Get dimensions
	int getFontSize();
	int getWidth();
	int getHeight();

private:
	SDL_Texture* mTexture;

	TTF_Font* mFont = NULL;

	//Variable to store last use of font
	std::string mText;
	std::string mPathToFont;
	SDL_Color mColor;
	int mFontSize = 0;

	int mWidth;
	int mHeight;
};

#endif