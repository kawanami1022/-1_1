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
	void operator()(PayType& payType, PairInt& cardData, int card)
	{
		cardData = lpCardServer.GetCardState();
	}
};