#include "Tree.h"

Tree::Tree()
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
}
Tree::~Tree()
{

}



bool Tree::initialise(SDL_Texture* texture, int posX, int posY, int width, int height,
	float angle, SDL_Point* centrePoint, SDL_Rect* clip, SDL_RendererFlip flip)
{
	bool success = true;
	
	mTexture = texture;
	int randNum = (rand()% 4)+1;
	if (randNum ==1){
		loadFromFile("res/img/tree1.png");
	}
	else if (randNum == 2){
		loadFromFile("res/img/tree2.png");
	}
	else if (randNum == 3){
		loadFromFile("res/img/tree3.png");
	}
	else if (randNum == 4){
		loadFromFile("res/img/tree4.png");
	}
	
	mPosX = posX;
	mPosY = posY;
	mWidth = width;
	mHeight = height;
	mAngle = angle;
	mCentrePoint = centrePoint;
	mClip = clip;
	mFlip = flip;

	return success;
}
void Tree::update(float dt)
{
	
}