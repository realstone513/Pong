#pragma once
#include "../3rd/SingleTon.h"
#include <SFML/Audio.hpp>
#include <list>

#define SOUND_MGR (SoundManager::GetInstance())

using namespace sf;
using namespace std;

class SoundManager : public Singleton<SoundManager>
{
private:
	list<Sound*> playing;
	list<Sound*> waiting;

	float globalVolume;

public:
	SoundManager();
	virtual ~SoundManager();
	
	const int TotalChannels;

	void Init();
	void Release();

	void Play(string id, bool loop = false);
	void StopAll();

	void Update();
};