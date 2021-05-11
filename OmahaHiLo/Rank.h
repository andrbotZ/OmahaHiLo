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
	enum  RankType { StraightFlushType, FourOfaKindType, FullHouseType, FlushType, StraightType, ThreeOfaKindType, TwoPairType, OnePairType, HighCardType};


	public:
		
		RankType HighestRank;
		RankType LowestRank;
	

	public:
		void UpdateHighest(vector<Card> cards);
		void UpdateLowest(vector<Card> cards);
		vector<Card> SortCards(vector<Card> cards);
		bool CompareHighestRank(RankType rank);
		string GetHighestRank();
		string GetLowestRank();
		
};

