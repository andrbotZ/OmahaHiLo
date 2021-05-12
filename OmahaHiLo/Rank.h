#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "RoyalFlush.h"
#include "StraightFlush.h"
#include "FourOfKind.h"
#include "FullHouse.h"
#include "ThreeOfKind.h"
#include "LowestRank.h"

class Rank
{

	enum  RankType { None, HighCardType, OnePairType, TwoPairType, ThreeOfaKindType, StraightType, FlushType, FullHouseType, FourOfaKindType, StraightFlushType, RoyalFlushType};

	public:
		
		RankType HighestRank;
		int LowestRankValue;
	

	public:
		void UpdateHighest(vector<Card> cards);
		void UpdateLowest(vector<Card> cards);
		vector<Card> SortCards(vector<Card> cards);
		bool CompareHighestRank(RankType rank);
		bool CompareLowestRank(int rank);	
		string GetHighestRank();
		string GetLowestRank();
		
};

