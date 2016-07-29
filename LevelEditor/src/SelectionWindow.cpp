#include "SelectionWindow.h"
//TODO initialise camera
std::vector<ObjectType*> ObjectType::mObjectTypes;

SelectionWindow::SelectionWindow()
{
	
}

bool SelectionWindow::initialise(SDL_Rect* windowRect)
{
	bool success = true;
	CreateObjectTypes();
	std::vector<ObjectType*> gameObjects = ObjectType::getObjectTypes();

	for (int i = 0; i < gameObjects.size(); ++i)
	{
		//TODO remove temporary creation of SDL_Textures
		SDL_Texture* tempTexture;
		{
			std::string pathStr = "res/img/" + gameObjects[i]->getTextureId() + ".png";
			const char* pathChar = pathStr.c_str();
			tempTexture = SDL_CreateTextureFromSurface(SceneRenderer, IMG_Load(pathChar));
		}
		thumbnails.push_back(Thumbnail(tempTexture, gameObjects[i]->getObjectId()));
		delete tempTexture;
	}
	
	for (int i = 0; i < thumbnails.size(); ++i)
	{
		SDL_Rect* thumbnailRect = new SDL_Rect();
		//Position thumbnails in the window 2 across by N down;
		if (i % 2 == 0)
		{
			thumbnailRect->x = 10;
			thumbnailRect->y = i * 100;
		}
		else{
			thumbnailRect->x = 110;
			thumbnailRect->y = (i -1) * 100;
		}

		thumbnails[i].initialise(thumbnailRect);
		//todo Write the name of the object under the thumbnail as well. (Thumbnails should maybe have a fonttexture.
	}

	return success;
}

bool SelectionWindow::update()
{
	for (int i = 0; i < thumbnails.size(); ++i){
		//thumbnails[i].render(mCamera);
	}
	return true;
}