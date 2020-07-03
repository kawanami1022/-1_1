#pragma once
#include "TicketMachine.h"
struct InsertMax
{
	bool operator()(PayType& payType, MapInt& cashData, int cash)
	{
		return true;
	}
}