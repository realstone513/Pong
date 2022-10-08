#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include "../3rd/rapidcsv.h"
#include "../3rd/SingleTon.h"

#define RESOURCES_MGR (ResourceManager::GetInstance())

using namespace sf;
using namespace std;

enum class ResourcesTypes
{
	Texture, Font, SoundBuffer
};

class ResourceManager : public Singleton<ResourceManager>
{
private:
	map<string, Texture*> texMap;
	map<string, Font*> fontMap;
	map<string, SoundBuffer*> soundMap;

public:
	static string filePath;
	ResourceManager();
	~ResourceManager();
	
	bool LoadAll();
	bool LoadTexture(string id);
	bool LoadFont(string id);
	bool LoadSoundBuffer(string id);
	bool Load(ResourcesTypes type, string id);
	void Release();
	Texture* GetTexture(string id);
	Font* GetFont(string id);
	SoundBuffer* GetSoundBuffer(string id);
};