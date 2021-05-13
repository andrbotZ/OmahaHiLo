#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include"LowestRank.h"
#include"ThreeOfKind.h"
#include"Flush.h"
#include"Straight.h"

#include"OnePair.h"

class Rank
{

	enum  RankType { None, HighCardType, OnePairType, TwoPairType, ThreeOfaKindType, StraightType, FlushType, FullHouseType, FourOfaKindType, StraightFlushType, RoyalFlushType};

	private:
		void printCards(vector<Card> cards);

	public:
		
		RankType HighestRank;
		int LowestRankValue;
	

	public:
		void UpdateHighest(vector<Card> cards);
		void UpdateLowest(vector<Card> cards);
		vector<Card> SortCards(vector<Card> cards);
		int CompareHighestRank(RankType rank);
		int CompareLowestRank(int rank);	
		string GetHighestRank();
		string GetLowestRank();
		
};

