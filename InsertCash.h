#pragma once
#include "TicketMachine.h"

struct InsertCash
{
	void operator()(PayType& payType, MapInt& cashData, int cash)
	{
		cashData.try_emplace(cash, 0);
		cashData[cash]++;
	}
};