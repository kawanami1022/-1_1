#pragma once
#include "TicketMachine.h"
struct InsertMax
{
	bool operator()(PayType& payType, MapInt& cardData, int card)
	{
		// �J�[�h�̎c���ƈ�������z���擾
		return true;
	}
};