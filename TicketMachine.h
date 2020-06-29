#pragma once
#include <functional>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "MouseCt1.h"
#include "CardServer.h"

#define lpTicketMachine TicketMachine::getInstance()

using MapInt = std::map<int, int>;
using VecInt = std::vector<int>;
using sharedMouse = std::shared_ptr<MouseCt1>;

enum class PayType {
	CASH,		// ����
	CARD,		// IC�J�[�h
	MAX			// ���ݒ�
};


class TicketMachine
{
public:
	static TicketMachine& getInstance()
	{
		static TicketMachine s_Instance;
		return s_Instance;
	}
	void Run(void);
	bool InsertCash(int cash);		// ������t����
	void Draw(void);
	bool InsertCard();			// �d�q�}�l�[�J�[�h�̎�t����
	VecInt& GetMoneyType(void);
	bool Init(sharedMouse mouse);

private:
	bool InitDraw(void);
	bool PayCash();
	void Clear();
	void DrawBtn(void);
	sharedMouse mouse;			//
	
	Vector2 btnPos;				// ����(�󂯎��)�{�^���̕\���ʒu
	std::string btnKey;			// �\������{�^���ւ̃L�[
	std::vector<int> moneyType;	// �x�����@
	PayType payType;				// �x�����@
	MapInt cashData;				// ����
	MapInt cashDataChange;		// ���ނ�
	PairInt cardData;				//
	bool paySuccess;


	std::map<std::string, int> images;
	std::map < PayType, std::function<void(void)>> draw;

	const int comment_offsetY;
	const int draw_offsetX;
	const int draw_offsetY;
	const int price_cash;
	const int price_card;

	const int pay_btn_sizeX;		// �x���{�^���̏c�T�C�Y
	const int pay_btn_sizeY;
	const int screen_sizeX;		// ��ʂ̏c�̉𑜓x
	const int screen_sizeY;		// ��ʂ̉��̉𑜓x
	const int money_sizeX;		// �����̉��̃T�C�Y
	const int money_sizeY;		// �����̉��̃T�C�Y
	const int font_size;			// �t�H���g�̃T�C�Y

	TicketMachine();
	~TicketMachine();
};