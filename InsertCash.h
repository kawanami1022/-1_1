#pragma once
#include "TicketMachine.h"

struct InsertCash
{
	void operator()(PayType& payType, MapInt& cashData, int cash)
	{
		if (payType == PayType::MAX)
		{
			payType = PayType::CASH;
		}

		if (payType != PayType::CASH)
		{
			return;
		}


		cashData.try_emplace(cash, 0);
		cashData[cash]++;
	}
};