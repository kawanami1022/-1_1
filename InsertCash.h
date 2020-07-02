#pragma once
#include "TicketMachine.h"

struct InsertCash
{
	bool operator()(PayType& payType, MapInt& cashData, int cash)
	{
		//if (payType == PayType::MAX)
		//{
		//	payType = PayType::CASH;
		//}

		//if (payType != PayType::CASH)
		//{
		//	return false;
		//}
		//if (payType != PayType::CASH)

		cashData.try_emplace(cash, 0);
		cashData[cash]++;
		return true;
	}
};