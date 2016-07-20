//To load a new file:
//Add the file name to the appropriate list in setMediaToLoad()
//Audio files go in the snd subfolder folder (.wav only)
//Image files go in the img subfolder (.png only)

#include "ResourceManager.h"
ResourceManager* ResourceManager::m_instance = 0;

ResourceManager::ResourceManager(void)
{
}

ResourceManager::~ResourceManager(void)
{
}

ResourceManager* ResourceManager::instance(){
	if(0 == m_instance){
		m_instance = new ResourceManager();
	}
	return m_instance;
}

bool ResourceManager::loadAllMedia()
{
	bool mediaLoaded = false;
	setMediaToLoad();
	if(SceneRenderer)
	{
		if(loadSfx() && loadImages() && loadMusic())
		{
			mediaLoaded = true;
		}
	}
	return mediaLoaded;
}

//Loads all sound effect files. Warning: only loads .wav files!"
//TODO reduce the number of files loaded only to what is necessary for the scene. Can be done relatively easy by creating a separate list of sfx names
bool ResourceManager::loadSfx()
{
	bool mediaLoaded = true;
	for (int i = 0; i < m_sfxNames.size(); i++)
	{
		std::string pathStr = "res/snd/fx/" + m_sfxNames.at(i) + ".wav";
		const char* pathChar = pathStr.c_str();
		m_sfxMap[m_sfxNames.at(i)] = Mix_LoadWAV(pathChar);
		if(m_sfxMap[m_sfxNames.at(i)] == NULL)
		{
			mediaLoaded = false;
			printf("Failed to load sound effect: %s\n", m_sfxNames[i]);
		}
	}
	return mediaLoaded;
}

//Loads all music files. Warning: only loads .wav files!"
//TODO reduce the number of files loaded only to what is necessary for the scene. Can be done relatively easy by creating a separate list of song names
bool ResourceManager::loadMusic()
{//load all mus files
	bool mediaLoaded = true;
	for (int i = 0; i < m_musicNames.size(); i++)
	{
		std::string pathStr = "res/snd/mus/" + m_musicNames.at(i) + ".wav";
		const char* pathChar = pathStr.c_str();
		m_musicMap[m_musicNames.at(i)] = Mix_LoadMUS(pathChar);
		if(m_musicMap[m_musicNames.at(i)] == NULL)
		{
			mediaLoaded = false;
			printf("Failed to load music: %s\n", m_musicNames[i]);
		}
	}
	return mediaLoaded;
}

//Loads all image files. Warning: only loads .png files!"
//TODO reduce the number of files loaded only to what is necessary for the scene. Can be done relatively easy by creating a separate list of image names
bool ResourceManager::loadImages()
{//loads all image files in the setMediaToLoad method
	bool mediaLoaded = true;
	for (int i = 0; i < m_imageNames.size(); i++)
	{
		std::string pathStr = "res/img/" + m_imageNames.at(i) + ".png";
		const char* pathChar = pathStr.c_str();
		SDL_Texture* temp = SDL_CreateTextureFromSurface(SceneRenderer, IMG_Load(pathChar));

		m_textureMap[m_imageNames.at(i)] = SDL_CreateTextureFromSurface(SceneRenderer, IMG_Load(pathChar));
		if(m_textureMap[m_imageNames.at(i)] == NULL)
		{
			mediaLoaded = false;
			printf("Failed to load image: %s\n", m_imageNames[i]);
		}
	}
	return mediaLoaded;
}

void ResourceManager::setMediaToLoad()
{
	//images (.png only!)
	m_imageNames.push_back("default");
	m_imageNames.push_back("dot");

	//sfx (.wav only!)
	m_sfxNames.push_back("high");
	m_sfxNames.push_back("low");
	m_sfxNames.push_back("medium");
	m_sfxNames.push_back("Scratch1");
	m_sfxNames.push_back("steps");

	//music (.wav only!)
	m_musicNames.push_back("ambient");
	m_musicNames.push_back("default");
}

Mix_Chunk* ResourceManager::getSfx(std::string p_audioName)
{//p_audioName should not contain file extention
	return m_sfxMap[p_audioName];
}

Mix_Music* ResourceManager::getMusic(std::string p_audioName)
{//p_audioName should not contain file extention
	return m_musicMap[p_audioName];
}
	
SDL_Texture* ResourceManager::getTexture(std::string p_imageName)
{//p_imageName should not contain file extention
	bool imageFound = false;
	for(int i =0; i < m_imageNames.size(); i++){
		if(p_imageName == m_imageNames.at(i))
		{
			imageFound = true;
			return m_textureMap[p_imageName];
		}
	}

	return m_textureMap["default"];
}

bool ResourceManager::checkImageLoaded(std::string p_imageName)
{
	bool isImageLoaded = false;
	for(int i = 0; i < m_imageNames.size(); i++)
	{
		if(m_imageNames.at(i) == p_imageName)
		{
			isImageLoaded = true;
			break;
		}
	}
	return isImageLoaded;
}