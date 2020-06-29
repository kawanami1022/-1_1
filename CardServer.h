#pragma once
#include <utility>

#define lpCardServer CardServer::GetInstance()

using PairInt = std::pair<int, int>;

class CardServer
{
public: 

	static CardServer& GetInstance()
	{
		static CardServer s_instance;
		return s_instance;
	}
	PairInt GetCardState(void);
	bool Payment(int price);
private:
	CardServer();
	~CardServer();
	PairInt cardData;

};

