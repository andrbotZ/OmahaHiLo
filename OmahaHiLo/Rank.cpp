#include "Rank.h"
#include <iostream>



void Rank::UpdateHighest(vector<Card> playerCards)
{
	playerCards = SortCards(playerCards);
	RoyalFlush royalFlush;
	bool isRoyalFlush = royalFlush.Validate(playerCards);

	StraightFlush straightFlush;
	bool isStraightFlush = straightFlush.Validate(playerCards);

	FourOfKind fourOfKind;
	bool isFourOfKind = fourOfKind.Validate(playerCards);
	
	FullHouse fullHouse;
	bool isFullHouse = fullHouse.Validate(playerCards);

}

void Rank::UpdateLowest(vector<Card> cards)
{
	std::cout << cards[0].rank + cards[0].suit + "-" + cards[1].rank + cards[1].suit + "-" + cards[2].rank + cards[2].suit + "-" + cards[3].rank + cards[3].suit + "-" + cards[4].rank + cards[4].suit << '\n';
}

bool Rank::CompareHighestRank(RankType rank)
{
	
	return false;
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
