#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "RoyalFlush.h"
#include "StraightFlush.h"
#include "FourOfKind.h"
#include "FullHouse.h"

class Rank
{
	enum RankType { dd };

	public:
		
		string HighestRank;
		string LowestRank;
	

	public:
		void UpdateHighest(vector<Card> cards);
		void UpdateLowest(vector<Card> cards);
		vector<Card> SortCards(vector<Card> cards);
		bool CompareHighestRank(string rank);
		
};

