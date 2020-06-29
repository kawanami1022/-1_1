#pragma once
class Sound
{
public:
	static Sound& GetInstance();

private:
	Sound();
	~Sound();
	static Sound* sInstance;
};

