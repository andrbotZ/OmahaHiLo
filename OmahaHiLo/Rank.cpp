#include "Rank.h"
#include <iostream>


static const char* enum_str[] = { "None", "High Card", "One Pair", "Two Pair", "Three Of Kind", "Straight", "Flush","Full House", "Four Of Kind", "Straight Flush", "Royal Flush" };

void Rank::UpdateHighest(vector<Card> playerCards)
{
	playerCards = SortCards(playerCards);

	RoyalFlush royalFlush;

	if (royalFlush.Validate(playerCards)) {
		CompareHighestRank(RoyalFlushType);
	}

	StraightFlush straightFlush;
 
	if (straightFlush.Validate(playerCards)) {
		CompareHighestRank(StraightFlushType);
	}

	FourOfKind fourOfKind;
 
	if (fourOfKind.Validate(playerCards)) {
		CompareHighestRank(FourOfaKindType);
	}

	FullHouse fullHouse;
 
	if (fullHouse.Validate(playerCards)) {
		CompareHighestRank(FullHouseType);
	}

	ThreeOfKind threeOfaKindType;
 
	if (threeOfaKindType.Validate(playerCards)) {
		if (!CompareHighestRank(ThreeOfaKindType)) {
			HighestRank = ThreeOfaKindType;
		}
	}

}
 

void Rank::UpdateLowest(vector<Card> playerCards)
{
	playerCards = SortCards(playerCards);
	LowestRank lowestRank;
	int _rank = lowestRank.Convert(playerCards);

	if (!CompareLowestRank(_rank)) {
		LowestRankValue = _rank;
	}
	

}

bool Rank::CompareHighestRank(RankType rank)
{
	int one = static_cast<int>(HighestRank);
	int two = static_cast<int>(rank);
	if (one > two) return true;

	return false;
}

bool Rank::CompareLowestRank(int rank)
{
	int one = LowestRankValue;
	int two = rank;
	if (one >= two) return true;

	return false;
}

string Rank::GetHighestRank()
{
	string rank{ enum_str[HighestRank] };
	return rank;
}

string Rank::GetLowestRank()
{	 
	string str;
	if (LowestRankValue == 0) {
		str = "No hand qualified for Low";
	}
	else {
		str = to_string(LowestRankValue);
	}
	return str;
}

 

vector<Card> Rank::SortCards(vector<Card> cards)
{
	for (int i = 0; i < cards.size() - 1; i++) {
		for (int j = 0; j < cards.size() - i - 1; j++) {
			if (cards[j].value < cards[j + 1].value) {
				Card tempCard{ cards[j].rank + cards[j].suit };
				cards[j] = cards[j + 1];
				cards[j + 1] = tempCard;
			}
		}

	}
	return cards;
}
