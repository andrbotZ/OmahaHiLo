#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "RoyalFlush.h"

class Rank
{
	public:
		string HighestRank;
		string LowestRank;
	

	public:
		void Update(vector<Card> playerCards, vector<Card> boardCards);
};

