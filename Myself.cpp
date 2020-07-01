#include <DxLib.h>
#include "MouseCt1.h"
#include "TicketMachine.h"
#include "Myself.h"
#include "_debug/_DebugConOut.h"

Myself* Myself::s_Instance = nullptr;

bool Myself::Run(void)
{
	if (!SysInit())
	{
		return false;
	}
	if (!MyInit())
	{
		return false;
	}

	if (!lpTicketMachine.Init(mouse))
	{
		return false;
	}

	const VecInt& moneyType = lpTicketMachine.GetMoneyType();
	// ループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		mouse->Update();
		if (mouse->GetClickTrg())
		{
			Vector2 pos = mouse->GetPos();
			if (pos.x < money_sizeX)
			{
				if( pos.y < money_sizeY*static_cast<int>(moneyType.size()))	// moneyTypeの要素内をチェックする
				{
					int type = moneyType[pos.y / money_sizeY];
					if (0<cash[type])
					{
						//if (lpTicketMachine.GetInsert()[InsertType::CASH](type))
						if (lpTicketMachine.InsertCash(type))
						{
							cash[type]--;
						}
					}
				}
				else
				{
					// 現金の範囲+1の位置がちょうど電子マネー
					if (pos.y < static_cast<int>(moneyType.size() + 1) * money_sizeY)
					{
						//lpTicketMachine.GetInsert()[InsertType::CARD](0);
						lpTicketMachine.InsertCard();
					}
				}
			}

		}

		lpTicketMachine.Run();
		SetDrawScreen(DX_SCREEN_BACK);
		ClsDrawScreen();
		Draw();
		ScreenFlip();
	}

	return true;
}

void Myself::Draw()
{
	auto moneyLine=0;
	SetFontSize(font_size);
	for (auto cashData:cash)
	{
		DrawFormatString(money_sizeX + 25,
			money_sizeY * moneyLine + money_sizeY / 3,
			0xffffff,
			"%d 枚",
			cashData.second);
		moneyLine++;
	}
	// 切符の値段表示
	DrawString(screen_sizeX/2-font_size,
		money_sizeY/2,
		"切符の価格  現金:130円　電子マネー:124円" ,0xffffff, true);
	const VecInt& moneyType = lpTicketMachine.GetMoneyType();
	// 仕切り線
	DrawLine(
		0,
		money_sizeY * (moneyType.size() + 1),
		screen_sizeX, money_sizeY * (moneyType.size() + 1),
		0xffffff,
		true);
	DrawLine(
		money_sizeX * 2,
		0,
		money_sizeX * 2,
		money_sizeY * ((moneyType.size()+1)),
		0xffffff,
		true);

	
	lpTicketMachine.Draw();
}

bool Myself::MargeCash(MapInt& changeCash)
{
	//auto typeVec=lpTicketMachine.GetMoneyType();
	//for (int j = 0; j < typeVec.size(); j++)
	//{
	//	if (changeCash.count(typeVec[j]))
	//	{cash[typeVec[j]] += changeCash[typeVec[j]];}
	//}

	for (auto data : changeCash)
	{
		cash[data.first] += data.second;
	}
	return true;
}




bool Myself::SysInit()
{
	ChangeWindowMode(true);
	SetGraphMode(screen_sizeX, screen_sizeY, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return false;				// エラーが起きたら直ちに終了
	}
	SetFontSize(font_size);
	return true;
}

bool Myself::MyInit()
{
	// 宣言と中身の作成を同時にする場合
	//std::unique_ptr<MouseCt1> mouse(new MouseCt1());
	//mouse.reset(new MouseCt1());

	mouse = std::make_shared<MouseCt1>();

	if (!mouse)
	{
		return false;
	}

	// 保持する現金を追加
	cash.try_emplace(10, 15);
	cash.try_emplace(50, 13);
	cash.try_emplace(100, 2);
	cash.try_emplace(500, 1);
	cash.try_emplace(1000, 1);
	cash.try_emplace(5000, 1);
	cash.try_emplace(10000, 1);
	return true;
}

Myself::Myself():
	screen_sizeX(800),screen_sizeY(600), 
	money_sizeX(100), money_sizeY(50),
	font_size(18)
{
	TRACE("Myselfを生成\n");
}

Myself::~Myself()
{
	TRACE("Myselfを破棄\n");
}
