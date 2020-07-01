#pragma once
#include <mutex>
#include <memory>
#include <map>
#include <vector>
#include "TicketMachine.h"

#define lpMyself Myself::GetInstance()
// 1����MAX�Ŕ��肵C,B�ŕ���
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
	const int screen_sizeX;		// ��ʂ̏c�̉𑜓x
	const int screen_sizeY;		// ��ʂ̉��̉𑜓x
	const int money_sizeX;		// �����̉��̃T�C�Y
	const int money_sizeY;		// �����̉��̃T�C�Y
	const int font_size;			// �t�H���g�̃T�C�Y

	// unique_ptr��unique_ptr�̃����o�[
	//	��		��unique_ptr�̃����o�[�̈�Ƃ��āAMouseCtl���Ǘ�����|�C���^	���@MouseCt1�̃����o�[
	// mouse 

	sharedMouse mouse;
	std::map<std::string, int> images;
	MapInt cash;

	Myself();
	~Myself();
	static Myself* s_Instance;
};

