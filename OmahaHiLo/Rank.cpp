#include "Rank.h"
#include <iostream>

void Rank::UpdateHighest(vector<Card> playerCards)
{
	RoyalFlush royalFlush;
	bool isRoyalFlush = royalFlush.Validate(playerCards);

}

void Rank::UpdateLowest(vector<Card> cards)
{
	std::cout << cards[0].rank + cards[0].suit + "-" + cards[1].rank + cards[1].suit + "-" + cards[2].rank + cards[2].suit + "-" + cards[3].rank + cards[3].suit + "-" + cards[4].rank + cards[4].suit << '\n';
}
