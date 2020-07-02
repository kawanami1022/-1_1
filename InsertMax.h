#pragma once
#include "TicketMachine.h"
struct InsertMax
{
	bool operator()(PayType& payType, MapInt& cardData, int card)
	{
		// カードの残高と引き去り額を取得
		return true;
	}
};