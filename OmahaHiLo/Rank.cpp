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
 

void Rank::UpdateLowest(vector<Card> cards)
{
	// std::cout << cards[0].rank + cards[0].suit + "-" + cards[1].rank + cards[1].suit + "-" + cards[2].rank + cards[2].suit + "-" + cards[3].rank + cards[3].suit + "-" + cards[4].rank + cards[4].suit << '\n';
}

bool Rank::CompareHighestRank(RankType rank)
{
	int one = static_cast<int>(HighestRank);
	int two = static_cast<int>(rank);
	if (one > two) return true;

	return false;
}

string Rank::GetHighestRank()
{
	string rank{ enum_str[HighestRank] };
	return rank;
}

string Rank::GetLowestRank()
{

	string rank{ enum_str[LowestRank] };
	return rank;
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
