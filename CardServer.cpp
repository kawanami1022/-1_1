#include "CardServer.h"

// Œ»Ý‚ÌŽc‚‚Æˆø‹ŽŠz‚ðŽæ“¾‚·‚éŠÖ”(first:Žc‚ second:ˆø‹ŽŠz)
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
