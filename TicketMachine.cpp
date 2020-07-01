#include <algorithm>
#include <vector>
#include <DxLib.h>
#include "TicketMachine.h"
#include "Myself.h"
#include "_debug/_DebugConOut.h"
#include "CardServer.h"


void TicketMachine::Run(void)
{
	Vector2 pos = mouse->GetPos();
	
	auto checkBtn = [&]() {
		if ((pos.x >= btnPos.x && pos.x < btnPos.x + pay_btn_sizeX) &&
			(pos.y >= btnPos.y && pos.y < btnPos.y + pay_btn_sizeY))
		{
			return true;
		}
		return false;
	};

	if (mouse->GetClicking() &&checkBtn())
	{
		btnKey = "btn_push";
	}
	else
	{
		btnKey = "btn";
	}
	if (mouse->GetClickTrg() && checkBtn())
	{
		if (paySuccess)
		{
			if (lpMyself.MargeCash(cashDataChange))
			{
				Clear();
			}
		}
		else
		{

			if (pay.count(payType))
			{
				pay[payType]();
			}
			else
			{
				TRACE("エラー:未知の支払い方法");
				payType = PayType::MAX;
			}

			//// 決済処理の実行
			//switch (payType)
			//{
			//case PayType::CASH:

			//	if (PayCash())
			//	{
			//		// 決済成功
			//		TRACE("決済成功\n");
			//	}
			//	break;
			//case PayType::CARD:
			//	//lpCardServer.Payment(price_card);
			//	//cardData = lpCardServer.GetCardState();
			//	//paySuccess = true;
			//	break;
			//case PayType::MAX:
			//	break;
			//default:
			//	TRACE("エラー:未知の支払い方法");
			//		payType = PayType::MAX;
			//	break;
			//}
		}
	}
}

bool TicketMachine::Insert(void)
{
	//if (payType == PayType::MAX)
	//{
	//	payType = PayType::CASH;
	//}

	//if (payType != PayType::CASH)
	//{
	//	return false;
	//}

	//cashData.try_emplace(cash, 0);
	//cashData[cash]++;

	//if (payType == PayType::MAX)
	//{
	//	payType = PayType::CARD;
	//}
	//else
	//{
	//	//カードおよび現金のみ
	//	return false;
	//}
	//cardData = lpCardServer.GetCardState();
	return true;
}

bool TicketMachine::InsertCash(int cash)
{
	//try
	//{
	//	cashData.at(cash)++;
	//}
	//catch(...)
	//{
	//	cashData.emplace(cash, 1);
	//}


	if (payType == PayType::MAX)
	{
		payType = PayType::CASH;
	}

	if (payType != PayType::CASH)
	{
		return false;
	}

	cashData.try_emplace(cash, 0);
	cashData[cash]++;

	return true;
}


bool TicketMachine::InsertCard()
{
	if (payType == PayType::MAX)
	{
		payType = PayType::CARD;
	}
	else
	{
		//カードおよび現金がみ
		return false;
	}
	cardData = lpCardServer.GetCardState();
	return true;
}

void TicketMachine::Draw(void)
{
	// C++20 
	//if(draw.contains(PayType))
	//{ 
	//	draw[payType]();
	//}

	//if (draw.find(payType) != draw.end())
	//{
	//	draw[payType]();
	//}

	if (draw.count(payType))
	{
		draw[payType]();
	}
	//int moneyLine = 0;
	//int totalMoney = 0;
	//SetFontSize(font_size);
	//// 切符の値段表示
	//DrawString(screen_sizeX / 2 - font_size,
	//	money_sizeY / 2,
	//	"切符の価格  現金:130円　電子マネー:124円", 0xffffff, true);

	//switch(payType)
	//{
	//case PayType::CASH:
	//	//DrawGraph(0, 0, images["money"], true);
	//	//if (paySuccess)
	//	//{
	//	//	DrawString(
	//	//		0, comment_offsetY + GetFontSize() / 2,
	//	//		"決済完了\nお釣りを受け取る際は受け取りボタンを押してください",
	//	//		0xffffff, true
	//	//	);
	//	//	DrawString(draw_offsetX, draw_offsetY, "投入金額", 0xffffff);
	//	//	DrawString(draw_offsetX, draw_offsetY, "             枚数", 0xffffff);
	//	//	for (auto moneyData : cashData)
	//	//	{
	//	//		DrawFormatString(
	//	//			draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
	//	//			0xffffff, "%d円", moneyData.first
	//	//		);
	//	//		DrawFormatString(draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
	//	//			0xffffff, "                %d枚", moneyData.second);
	//	//		moneyLine++;
	//	//		totalMoney += (moneyData.first * moneyData.second);
	//	//	}

	//	//	DrawFormatString(draw_offsetX, (draw_offsetY + GetFontSize() * 2) + moneyLine * GetFontSize(),
	//	//		0xffffff, "合計投入金額 %d円", totalMoney);
	//	//	DrawString(draw_offsetX * 2, draw_offsetY, "   釣銭", 0xffffff);
	//	//	DrawString(draw_offsetX * 2, draw_offsetY, "             枚数", 0xffffff);
	//	//	int changeLine = 0;
	//	//	for (auto data : cashDataChange)
	//	//	{
	//	//		DrawFormatString(draw_offsetX * 2, (draw_offsetY + GetFontSize()) + changeLine * GetFontSize(),
	//	//			0xffffff, "%5d円", data.first);
	//	//		DrawFormatString(draw_offsetX * 2, (draw_offsetY + GetFontSize()) + changeLine * GetFontSize(),
	//	//			0xffffff, "           %9d枚", data.second);
	//	//		changeLine++;
	//	//	}
	//	//}
	//	//else
	//	//{
	//	//	DrawString(
	//	//		0, comment_offsetY + GetFontSize() / 2,
	//	//		"左の枠内の現金化ICカードを選択しクリックして入金してください。\n入金んが完了したら決済ボタンを押してください.",
	//	//		0xffffff, true
	//	//	);
	//	//	DrawString(draw_offsetX, draw_offsetY, "投入金額", 0xffffff);
	//	//	DrawString(draw_offsetX, draw_offsetY, "             枚数", 0xffffff);
	//	//	for (auto moneyData : cashData)
	//	//	{
	//	//		DrawFormatString(
	//	//			draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
	//	//			0xffffff, "%d円", moneyData.first
	//	//		);
	//	//		DrawFormatString(draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
	//	//			0xffffff, "                %d枚", moneyData.second);
	//	//		moneyLine++;
	//	//		totalMoney += (moneyData.first * moneyData.second);
	//	//	}

	//	//	DrawFormatString(draw_offsetX, (draw_offsetY + GetFontSize() * 2) + moneyLine * GetFontSize(),
	//	//		0xffffff, "合計投入金額 %d円", totalMoney);

	//	//	if (totalMoney < price_cash)
	//	//	{
	//	//		DrawString(draw_offsetX, (draw_offsetY + GetFontSize() * 3) + moneyLine * GetFontSize(),
	//	//			"金額が足りません", 0xff0000, true);
	//	//	}
	//	//}
	//	break;
	//case PayType::CARD:
	//	//DrawGraph(0, 0, images["act_card"], true);
	//	//if (paySuccess)
	//	//{
	//	//	DrawString(0, comment_offsetY + GetFontSize() / 2,
	//	//		"決済完了\nICカードをだす際は受け取りボタンを押してください。",
	//	//		0xffffff);
	//	//	DrawString(draw_offsetX, draw_offsetY, "電子マネー", 0xffffff);
	//	//	DrawFormatString(draw_offsetX + GetFontSize(), draw_offsetY + GetFontSize(),
	//	//		0xffffff, " 残高  %d円", cardData.first);
	//	//	DrawFormatString(draw_offsetX + GetFontSize(), draw_offsetY + GetFontSize() * 2,
	//	//		0xffffff, " 引去額 %d円", cardData.second);
	//	//}
	//	//else
	//	//{
	//	//	DrawString(
	//	//		0, comment_offsetY + GetFontSize() / 2,
	//	//		"左の枠内の現金化ICカードを選択しクリックして入金してください。\n入金んが完了したら決済ボタンを押してください.",
	//	//		0xffffff, true
	//	//	);
	//	//	DrawString(draw_offsetX, draw_offsetY, "電子マネー", 0xffffff);
	//	//	DrawFormatString(draw_offsetX + GetFontSize(), draw_offsetY + GetFontSize(),
	//	//		0xffffff, " 残高　%d円", cardData.first);

	//	//	if (cardData.first < price_card)
	//	//	{
	//	//		DrawString(draw_offsetX, draw_offsetY + GetFontSize() * 3, "残高が足りません", 0xff0000, true);
	//	//	}
	//	//}
	//	break;
	//case PayType::MAX:
	//	//DrawGraph(0, 0, images["money"], true);
	//	//DrawString(
	//	//	0, comment_offsetY + GetFontSize() / 2,
	//	//	"左の枠内の現金化ICカードを選択しクリックして入金してください。\n入金んが完了したら決済ボタンを押してください.",
	//	//	0xffffff, true
	//	//);
	//	break;
	//default:
	//	TRACE("エラー:未知の支払い方法");
	//	break;
	//}
	DrawBtn();
}


VecInt& TicketMachine::GetMoneyType(void)
{
	// TODO: return ステートメントをここに挿入します
	return moneyType;
}

bool TicketMachine::InitDraw(void)
{
	int moneyLine = 0;
	SetFontSize(font_size);
	// 切符の値段表示
	DrawString(screen_sizeX / 2 - font_size,
		money_sizeY / 2,
		"切符の価格  現金:130円　電子マネー:124円", 0xffffff, true);

	draw.try_emplace(PayType::MAX, [&]() {
		int totalMoney = 0;
		int moneyLine = 0;
		SetFontSize(font_size);
		DrawGraph(0, 0, images["money"], true);
		DrawString(
			0, comment_offsetY + GetFontSize() / 2,
			"左の枠内の現金化ICカードを選択しクリックして入金してください。\n入金んが完了したら決済ボタンを押してください.",
			0xffffff, true
		);
	});
	draw.try_emplace(PayType::CASH, [&]() {
		int totalMoney = 0;
		int moneyLine = 0;
		SetFontSize(font_size);
		DrawGraph(0, 0, images["money"], true);
		if (paySuccess)
		{
			DrawString(
				0, comment_offsetY + GetFontSize() / 2,
				"決済完了\nお釣りを受け取る際は受け取りボタンを押してください",
				0xffffff, true
			);
			DrawString(draw_offsetX, draw_offsetY, "投入金額", 0xffffff);
			DrawString(draw_offsetX, draw_offsetY, "             枚数", 0xffffff);
			for (auto moneyData : cashData)
			{
				DrawFormatString(
					draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
					0xffffff, "%d円", moneyData.first
				);
				DrawFormatString(draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
					0xffffff, "                %d枚", moneyData.second);
				moneyLine++;
				totalMoney += (moneyData.first * moneyData.second);
			}

			DrawFormatString(draw_offsetX, (draw_offsetY + GetFontSize() * 2) + moneyLine * GetFontSize(),
				0xffffff, "合計投入金額 %d円", totalMoney);
			DrawString(draw_offsetX * 2, draw_offsetY, "   釣銭", 0xffffff);
			DrawString(draw_offsetX * 2, draw_offsetY, "             枚数", 0xffffff);
			int changeLine = 0;
			for (auto data : cashDataChange)
			{
				DrawFormatString(draw_offsetX * 2, (draw_offsetY + GetFontSize()) + changeLine * GetFontSize(),
					0xffffff, "%5d円", data.first);
				DrawFormatString(draw_offsetX * 2, (draw_offsetY + GetFontSize()) + changeLine * GetFontSize(),
					0xffffff, "           %9d枚", data.second);
				changeLine++;
			}
		}
		else
		{
			DrawString(
				0, comment_offsetY + GetFontSize() / 2,
				"左の枠内の現金化ICカードを選択しクリックして入金してください。\n入金んが完了したら決済ボタンを押してください.",
				0xffffff, true
			);
			DrawString(draw_offsetX, draw_offsetY, "投入金額", 0xffffff);
			DrawString(draw_offsetX, draw_offsetY, "             枚数", 0xffffff);
			for (auto moneyData : cashData)
			{
				DrawFormatString(
					draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
					0xffffff, "%d円", moneyData.first
				);
				DrawFormatString(draw_offsetX + GetFontSize(), (draw_offsetY + GetFontSize()) + moneyLine * GetFontSize(),
					0xffffff, "                %d枚", moneyData.second);
				moneyLine++;
				totalMoney += (moneyData.first * moneyData.second);
			}

			DrawFormatString(draw_offsetX, (draw_offsetY + GetFontSize() * 2) + moneyLine * GetFontSize(),
				0xffffff, "合計投入金額 %d円", totalMoney);

			if (totalMoney < price_cash)
			{
				DrawString(draw_offsetX, (draw_offsetY + GetFontSize() * 3) + moneyLine * GetFontSize(),
					"金額が足りません", 0xff0000, true);
			}
		}
	});
	draw.try_emplace(PayType::CARD, [&]() {
		DrawGraph(0, 0, images["act_card"], true);
		int totalMoney = 0;
		int moneyLine = 0;
		SetFontSize(font_size);
		if (paySuccess)
		{
			DrawString(0, comment_offsetY + GetFontSize() / 2,
				"決済完了\nICカードをだす際は受け取りボタンを押してください。",
				0xffffff);
			DrawString(draw_offsetX, draw_offsetY, "電子マネー", 0xffffff);
			DrawFormatString(draw_offsetX + GetFontSize(), draw_offsetY + GetFontSize(),
				0xffffff, " 残高  %d円", cardData.first);
			DrawFormatString(draw_offsetX + GetFontSize(), draw_offsetY + GetFontSize() * 2,
				0xffffff, " 引去額 %d円", cardData.second);
		}
		else
		{
			DrawString(
				0, comment_offsetY + GetFontSize() / 2,
				"左の枠内の現金化ICカードを選択しクリックして入金してください。\n入金んが完了したら決済ボタンを押してください.",
				0xffffff, true
			);
			DrawString(draw_offsetX, draw_offsetY, "電子マネー", 0xffffff);
			DrawFormatString(draw_offsetX + GetFontSize(), draw_offsetY + GetFontSize(),
				0xffffff, " 残高　%d円", cardData.first);

			if (cardData.first < price_card)
			{
				DrawString(draw_offsetX, draw_offsetY + GetFontSize() * 3, "残高が足りません", 0xff0000, true);
			}
		}
	});

	return false;
}

bool TicketMachine::InitPay(void)
{
	pay.try_emplace(PayType::CASH, [&]() { PayCash(); });
	pay.try_emplace(PayType::CARD, [&]() {PayCard(); });
	pay.try_emplace(PayType::MAX, [&]() {PayMax(); });
	return true;
}

bool TicketMachine::InitInsert(void)
{
	//insert.try_emplace(InsertType::CASH, [&](int cash) {
	//	if (payType == PayType::MAX)
	//	{
	//		payType = PayType::CASH;
	//	}

	//	if (payType != PayType::CASH)
	//	{
	//		return false;
	//	}

	//	cashData.try_emplace(cash, 0);
	//	cashData[cash]++;
	//	return true;
	//});
	//insert.try_emplace(InsertType::CARD, [&](int cash) {
	//	if (payType == PayType::MAX)
	//	{
	//		payType = PayType::CARD;
	//	}
	//	else
	//	{
	//		//カードおよび現金がみ
	//		return false;
	//	}
	//	cardData = lpCardServer.GetCardState();
	//	return true;
	//});
	return true;
}

bool TicketMachine::PayCash()
{
	int totalCash = 0;
	auto tmpCashData = cashData;

	// 投入金額合計
	for (auto cashData : tmpCashData)
	{
		totalCash += cashData.first * cashData.second;
	}

	if (totalCash < price_cash)
	{
		return false;
	}

	int credit = price_cash;
	for (auto& data : tmpCashData)
	{
		while (data.second)
		{
			credit -= data.first;
			data.second--;
			TRACE("使ったお金 : %d\n", data.first);
			if (credit <= 0)
			{
				break;
			}
		}
		if (credit <= 0)
		{
			// 支払いが終ってるのでお釣りの処理
			cashDataChange = tmpCashData;
			int change = -credit;
			paySuccess = true;
			//for (int i = moneyType.size() - 1; i >= 0; i--)
			//{
			//	cashDataChange[moneyType[i]] += (change / moneyType[i]);
			//	change -= (change / moneyType[i]) * moneyType[i];
			//	if(0<cashDataChange[moneyType[i]])
			//	TRACE("お釣り : %d円	%d枚\n",moneyType[i],cashDataChange[moneyType[i]])
			//}
			//for (int j = moneyType.size() - 1; j >= 0; j--)
			//{
			//	// お釣りがmoneyTypeより大きい
			//	while (change>=moneyType[j])
			//	{
			//		cashDataChange.try_emplace(moneyType[j], 0);
			//		cashDataChange[moneyType[j]]++;
			//		change -= moneyType[j];
			//	}
			//	if (change < 0)
			//	{
			//		TRACE("お釣り異常\n");
			//		return false;
			//	}
			//	if (change == 0)
			//	{
			//		return true;
			//	}
			//}
			std::for_each(moneyType.crbegin(), moneyType.crend(), [&](int type) {
				// お釣りがmoneyTypeより大きい
				while (change >= type)
				{
					cashDataChange.try_emplace(type, 0);
					cashDataChange[type]++;
					change -= type;
				}
			});
		
			if (change < 0)
			{
				TRACE("お釣り異常\n");
				return false;
			}
			if (change == 0)
			{
				TRACE("お釣り設定完了\n");
				return true;
			}

			break;
		}
	}
	paySuccess = false;
	return false;

}

bool TicketMachine::PayCard(void)
{
	lpCardServer.Payment(price_card);
	cardData = lpCardServer.GetCardState();
	paySuccess = true;
	return true;
}

bool TicketMachine::PayMax(void)
{
	return false;
}

void TicketMachine::Clear()
{
	btnKey = "btn";
	paySuccess = false;
	payType = PayType::MAX;
	cashData.clear();
	cashDataChange.clear();
	cardData = { 0,0 };
}

void TicketMachine::DrawBtn(void)
{
	SetFontSize(font_size * 2);

	std::string btnName = (paySuccess == false ? " 決 済" : "受け取り");

	DrawGraph(btnPos.x, btnPos.y, images[btnKey], true);

	DrawString(btnPos.x,
		btnPos.y+ (font_size / 2),
		btnName.c_str(),
		0x000000);
}

bool TicketMachine::Init(sharedMouse mouse)
{
	
	this->mouse = mouse;
	if (moneyType.size() == 0)
	{
		moneyType.emplace_back(10);
		moneyType.emplace_back(50);
		moneyType.emplace_back(100);
		moneyType.emplace_back(500);
		moneyType.emplace_back(1000);
		moneyType.emplace_back(5000);
		moneyType.emplace_back(10000);
	}

	// 画像の読み込み
	images.try_emplace("money", LoadGraph("image/money.png", true));
	images.try_emplace("act_cash", LoadGraph("image/active_cash.png", true));
	images.try_emplace("act_card", LoadGraph("image/active_card.png", true));
	images.try_emplace("btn", LoadGraph("image/btn.png", true));
	images.try_emplace("btn_push", LoadGraph("image/btn_push.png", true));
	btnPos= Vector2(
		(screen_sizeX - money_sizeX * 2) - pay_btn_sizeX,
		static_cast<int>(money_sizeY * (moneyType.size())));
	InitDraw();
	InitPay();
	InitInsert();
	return true;
}

//MapInsert& TicketMachine::GetInsert()
//{
//	// TODO: return ステートメントをここに挿入します
//	return insert;
//}

TicketMachine::TicketMachine() :comment_offsetY(450),
							draw_offsetX(200),draw_offsetY(70),
							price_cash(130),price_card(124),
							pay_btn_sizeX(200), pay_btn_sizeY(50),
							screen_sizeX(800), screen_sizeY(600),
							money_sizeX(100), money_sizeY(50),
							font_size(18)
{
	payType = PayType::MAX;
	paySuccess = false;
	TRACE("TicketMachineを生成\n");
}
TicketMachine::~TicketMachine()
{
	TRACE("TicketMachineを破棄\n");
}
