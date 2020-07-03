#pragma once
#include "TicketMachine.h"

//struct InsertCard
//{
//	void operator()(PayType& payType, PairInt& cardData, int card)
//	{
//		cardData = lpCardServer.GetCardState();
//	}
//};

struct InsertCard
{
	bool operator()(PayType& payType, MapInt& cardData, int card)
	{


		cardData.try_emplace(lpCardServer.GetCardState().first, lpCardServer.GetCardState().second);
		return true;
	}
};