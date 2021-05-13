#include "Rank.h"
#include <iostream>


static const char* enum_str[] = { "None", "High Card", "One Pair", "Two Pair", "Three Of Kind", "Straight", "Flush","Full House", "Four Of Kind", "Straight Flush", "Royal Flush" };

void Rank::printCards(vector<Card> cards)
{
	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
		Card card = *it;
		std::cout << card.rank + card.suit + "-" ;

	}
	std::cout << '\n';
}

void Rank::UpdateHighest(vector<Card> playerCards)
{
	playerCards = SortCards(playerCards);
 
	ThreeOfKind threeOfaKind;
 
	if (threeOfaKind.Validate(playerCards)) {
		if (CompareHighestRank(ThreeOfaKindType) == 2) {
			HighestRank = ThreeOfaKindType;
		}
	}

	Flush flush;

	if (flush.Validate(playerCards)) {
		if (CompareHighestRank(FlushType) == 2) {
			HighestRank = FlushType;
		}
	}

	Straight straight;

	if (straight.Validate(playerCards)) {
		if (CompareHighestRank(StraightType) == 2) {
			HighestRank = StraightType;
		}
	}

	OnePair onePair;

	if (onePair.Validate(playerCards)) {
		if (CompareHighestRank(OnePairType) == 2) {
			HighestRank = OnePairType;
		}
	}

	FullHouse fullHouse;

	if (fullHouse.Validate(playerCards)) {
		if (CompareHighestRank(FullHouseType) == 2) {
			HighestRank = FullHouseType;
		}
	}
 
}
 

void Rank::UpdateLowest(vector<Card> playerCards)
{
	playerCards = SortCards(playerCards);
	LowestRank lowestRank;
	if (lowestRank.Validate(playerCards)) {
		int _rank = lowestRank.result;
		if (LowestRankValue == 0) {
			LowestRankValue = _rank;
		}
		else {
			if (LowestRankValue >= _rank) LowestRankValue = _rank;
		}

	}

	
	

}

int  Rank::CompareHighestRank(RankType rank)
{
	int one = static_cast<int>(HighestRank);
	int two = static_cast<int>(rank);
	if (one > two) return 1;
	else if (one == two) return 0;
	return 2;
}

int Rank::CompareLowestRank(int rank)
{
 
	int one = LowestRankValue;
	int two = rank;
	if (one <= two) return 1;

	return 2;
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
