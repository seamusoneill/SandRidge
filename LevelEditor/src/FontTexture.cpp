#include "FontTexture.h"

FontTexture::FontTexture()
{
	mTexture = NULL;
	mFont = NULL;
	mWidth = 0;
	mHeight = 0;
	mFontSize = 0;
}

FontTexture::~FontTexture()
{
	free();
}

void FontTexture::free()
{
	//Deallocate texture
	if (mTexture != NULL)
	{		

		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
		if (mFont != NULL)
		{
			TTF_CloseFont(mFont);
			mFont = NULL;
			mFontSize = 0;
		}
	}

}	

bool FontTexture::loadFromFile(std::string text, std::string path, int size, SDL_Color color)
{
	//Get rid of preexisting texture and font
	free();

	//Set member variables to passed in variables
	mText = text;
	mPathToFont = path;
	mFontSize = size;
	mColor = color;

	//Load font
	mFont = TTF_OpenFont(mPathToFont.c_str(), mFontSize);
	if (mFont == NULL)
	{
		printf("Failed to open font file, TTF_Error: %s\n", TTF_GetError());
	}
	else
	{
		//Render text surface
		SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, mText.c_str(), mColor);
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! \nSDL_ttf Error %s\n", TTF_GetError());
		}
		else
		{
			//Create text from surface pixels
			mTexture = SDL_CreateTextureFromSurface(SceneRenderer, textSurface);
			if (mTexture == NULL)
			{
				printf("Unable to create texture from rendered text! \nSDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get image dimensions
				mWidth = textSurface->w;
				mHeight = textSurface->h;
			}

			//Get rid of old surface
			SDL_FreeSurface(textSurface);
		}
	}

	//Return success
	return mTexture != NULL;
}

void FontTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimesions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(SceneRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

//Set the font by passing in a new path and replacing the texture
void FontTexture::setFont(std::string path)
{
	if (!loadFromFile(mText, path, mFontSize, mColor))
	{
		printf("Failed to change FontTexture font!");
	}
}

//Change the text by replacing the old texture
void FontTexture::setText(std::string text)
{
	if (!loadFromFile(text, mPathToFont, mFontSize, mColor))
	{
		printf("Failed to change FontTexture text!");
	}
}

//Set color by replacing the texture
void FontTexture::setColor(SDL_Color color)
{
	if (!loadFromFile(mText, mPathToFont, mFontSize, color))
	{
		printf("Failed to change FontTexture color!");
	}
}

//Set font size by replacing the texture
void FontTexture::setFontSize(int size)
{
	if (!loadFromFile(mText, mPathToFont, size, mColor))
	{
		printf("Failed to change FontTexture size!");
	}
}

void FontTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void FontTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

int FontTexture::getFontSize()
{
	return mFontSize;
}

int FontTexture::getWidth()
{
	return mWidth;
}

int FontTexture::getHeight()
{
	return mHeight;
}