#include "Button.h"


Button::Button()
{
	//Initialise
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosX = 0;
	mPosY = 0;
	mAngle = 0.0;
	mCentrePoint = NULL;
	mClip = NULL;
	mFlip = SDL_FLIP_NONE;
	mVelX = 0;
	mVelY = 0;
	clicked = false;
}


Button::~Button()
{
}

bool Button::initialise(SDL_Texture* texture, int posX, int posY, int width, int height,
	float angle, SDL_Point* centrePoint, SDL_Rect* clip, SDL_RendererFlip flip)
{
	bool success = true;

	mTexture = texture;
	loadFromFile("res/img/dot.png"); 
	mPosX = posX;
	mPosY = posY;
	mWidth = width;
	mHeight = height;
	mAngle = angle;
	mCentrePoint = centrePoint;
	mClip = clip;
	mFlip = flip;
	clicked = false;
	return success;
}

void Button::update(float dt){
	//add event stuff here to chcange when something is clicked and to do something then.
}
void Button::update(SDL_Event* e){
	
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) //If mouse event happened
	{
		int x, y;
		SDL_GetMouseState(&x, &y); //Get mouse position
		bool inside = true;
		if (x < getX()){//Mouse is left of the button
			inside = false;
		}
		else if (x > getX() + 50){//Mouse is right of the button
			inside = false;
		}
		else if (y < getY()){//Mouse above the button
			inside = false;
		}
		else if (y > getY() + 50){//Mouse below the button
			inside = false;
		}
		if (!inside){//Mouse is outside button
			//mTexture = unclicked;
		}
		else{//Mouse is inside button
			switch (e->type){
			case SDL_MOUSEBUTTONDOWN:
				//mTexture = clicked;
				clicked = true;
				break;
			case SDL_MOUSEBUTTONUP:
				//mTexture = unclicked;
				SDL_Delay(1000);
				break;
			}
		}
	}
}

bool Button::IsClicked(){
	return clicked;
}