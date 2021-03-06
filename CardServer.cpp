#include "CardServer.h"

// 現在の残高と引去額を取得する関数(first:残高 second:引去額)
PairInt CardServer::GetCardState(void)
{
	return cardData;
}

bool CardServer::Payment(int price)
{
	if (cardData.first >= price)
	{
		cardData.first -= price;
		cardData.second = price;
		return true;
	}
	return false;
}

CardServer::CardServer()
{
	cardData = { 1000,0 };
}

CardServer::~CardServer()
{
}
