#pragma once
#include <functional>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "MouseCt1.h"
#include "CardServer.h"

#define lpTicketMachine TicketMachine::getInstance()
enum class PayType {
	CASH,		// ����
	CARD,		// IC�J�[�h
	MAX			// ���ݒ�
};

enum class InsertType {
	CASH,		// ����
	CARD,		// IC�J�[�h
};

using MapInt = std::map<int, int>;
using VecInt = std::vector<int>;
using sharedMouse = std::shared_ptr<MouseCt1>;
using MapInsert = std::map < InsertType, std::function<bool(int)>>;


class TicketMachine
{
public:
	static TicketMachine& getInstance()
	{
		static TicketMachine s_Instance;
		return s_Instance;
	}
	void Run(void);
	bool Insert(void);
	//bool (*InsertFunc)()
	bool InsertCash(int cash);		// ������t����
	bool InsertCard();			// �d�q�}�l�[�J�[�h�̎�t����
	void Draw(void);
	VecInt& GetMoneyType(void);
	bool Init(sharedMouse mouse);
	//MapInsert& GetInsert();

private:
	bool InitDraw(void);
	bool InitPay(void);
	bool InitInsert(void);
	bool PayCash(void);
	bool PayCard(void);
	bool PayMax(void);
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
	std::map < PayType, std::function<void(void)>> pay;
	//MapInsert insert;

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
