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
	// ���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		mouse->Update();
		if (mouse->GetClickTrg())
		{
			Vector2 pos = mouse->GetPos();
			if (pos.x < money_sizeX)
			{
				if( pos.y < money_sizeY*static_cast<int>(moneyType.size()))	// moneyType�̗v�f�����`�F�b�N����
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
					// �����͈̔�+1�̈ʒu�����傤�Ǔd�q�}�l�[
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
			"%d ��",
			cashData.second);
		moneyLine++;
	}
	// �ؕ��̒l�i�\��
	DrawString(screen_sizeX/2-font_size,
		money_sizeY/2,
		"�ؕ��̉��i  ����:130�~�@�d�q�}�l�[:124�~" ,0xffffff, true);
	const VecInt& moneyType = lpTicketMachine.GetMoneyType();
	// �d�؂��
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

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return false;				// �G���[���N�����璼���ɏI��
	}
	SetFontSize(font_size);
	return true;
}

bool Myself::MyInit()
{
	// �錾�ƒ��g�̍쐬�𓯎��ɂ���ꍇ
	//std::unique_ptr<MouseCt1> mouse(new MouseCt1());
	//mouse.reset(new MouseCt1());

	mouse = std::make_shared<MouseCt1>();

	if (!mouse)
	{
		return false;
	}

	// �ێ����錻����ǉ�
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
	TRACE("Myself�𐶐�\n");
}

Myself::~Myself()
{
	TRACE("Myself��j��\n");
}
