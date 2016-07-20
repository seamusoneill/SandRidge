#pragma once
#ifndef _RESOURCESMANAGER_H_
#define _RESOURCESMANAGER_H_

#include <SDL_image.h>
#include <SDL_mixer.h>
#include <map>
#include <string>
#include <vector>

#include "SceneManager.h"

class ResourceManager
{
public:
	static ResourceManager* m_instance;
	static ResourceManager* instance();

	bool loadAllMedia();
	Mix_Chunk* getSfx(std::string p_audioName);
	Mix_Music* getMusic(std::string p_audioName);
	SDL_Texture* getTexture(std::string p_imageName);

private:
	ResourceManager(void);
	~ResourceManager(void);

	bool loadSfx();
	bool loadMusic();
	bool loadImages();
	void setMediaToLoad();
	bool checkImageLoaded(std::string p_imageName);
	
	std::map<std::string, SDL_Texture*> m_textureMap;
	std::vector<std::string> m_imageNames;

	std::map<std::string, Mix_Chunk*> m_sfxMap;
	std::vector<std::string> m_sfxNames;
	
	std::map<std::string, Mix_Music*> m_musicMap;
	std::vector<std::string> m_musicNames;
};

#endif