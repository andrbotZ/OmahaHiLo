#include "Rank.h"

void Rank::Update(vector<Card> playerCards, vector<Card> boardCards)
{
	vector<Card> temp;
	temp.insert(temp.end(), playerCards.begin(), playerCards.end());
	temp.insert(temp.end(), boardCards.begin(), boardCards.end());

	RoyalFlush royalFlush;
	vector<Card> updatedPlayer = royalFlush.Validate(temp);
}
