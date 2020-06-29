#include "Sound.h"

Sound* Sound::sInstance = nullptr;


Sound& Sound::GetInstance()
{
	static Sound sInstance;
	return sInstance;
}

Sound::Sound()
{
}

Sound::~Sound()
{
}
