#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Rank
{
	public:
		string HighestRank;
		string LowestRank;

	public:
		void Update(vector<Card> cards);
};

