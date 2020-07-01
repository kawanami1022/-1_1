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
	CASH,		// 現金
	CARD,		// ICカード
	MAX			// 未設定
};

enum class InsertType {
	CASH,		// 現金
	CARD,		// ICカード
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
	bool InsertCash(int cash);		// 入金受付処理
	bool InsertCard();			// 電子マネーカードの受付処理
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
	
	Vector2 btnPos;				// 決済(受け取り)ボタンの表示位置
	std::string btnKey;			// 表示するボタンへのキー
	std::vector<int> moneyType;	// 支払方法
	PayType payType;				// 支払方法
	MapInt cashData;				// 現金
	MapInt cashDataChange;		// お釣り
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

	const int pay_btn_sizeX;		// 支払ボタンの縦サイズ
	const int pay_btn_sizeY;
	const int screen_sizeX;		// 画面の縦の解像度
	const int screen_sizeY;		// 画面の横の解像度
	const int money_sizeX;		// お金の横のサイズ
	const int money_sizeY;		// お金の横のサイズ
	const int font_size;			// フォントのサイズ

	TicketMachine();
	~TicketMachine();
};
