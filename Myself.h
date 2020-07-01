#pragma once
#include <mutex>
#include <memory>
#include <map>
#include <vector>
#include "TicketMachine.h"

#define lpMyself Myself::GetInstance()
// 1っ回MAXで判定しC,Bで分岐
class MouseCt1;

class Myself
{
public:
	static Myself& GetInstance()
	{
		static std::once_flag once;
		std::call_once(once, Create);
		return (*s_Instance);
	}
	static void Create()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new Myself();
		}
	}
	static void Destroy()
	{
		delete s_Instance;
		s_Instance = nullptr;
	}
	bool Run(void);
	void Draw();
	bool MargeCash(MapInt& changeCash);
private:
	bool SysInit();
	bool MyInit();
	const int screen_sizeX;		// 画面の縦の解像度
	const int screen_sizeY;		// 画面の横の解像度
	const int money_sizeX;		// お金の横のサイズ
	const int money_sizeY;		// お金の横のサイズ
	const int font_size;			// フォントのサイズ

	// unique_ptr→unique_ptrのメンバー
	//	↑		→unique_ptrのメンバーの一つとして、MouseCtlを管理するポインタ	→　MouseCt1のメンバー
	// mouse 

	sharedMouse mouse;
	std::map<std::string, int> images;
	MapInt cash;

	Myself();
	~Myself();
	static Myself* s_Instance;
};

