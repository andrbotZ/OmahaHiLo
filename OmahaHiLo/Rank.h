#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "RoyalFlush.h"
#include "StraightFlush.h"

class Rank
{
	public:
		string HighestRank;
		string LowestRank;
	

	public:
		void UpdateHighest(vector<Card> cards);
		void UpdateLowest(vector<Card> cards);
		vector<Card> SortCards(vector<Card> cards);
};

