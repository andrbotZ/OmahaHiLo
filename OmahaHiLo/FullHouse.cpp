#include "FullHouse.h"

bool FullHouse::Validate(vector<Card> cards)
{
	string suit;
	string rank;
	bool isSameKind{ false };

	for (int i = 0; i < cards.size(); i++)
	{
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}

	int sum = 0;
	for (int i = 0; i < cards.size() - 1; i++)
	{
		if (cards[i].value - cards[i + 1].value != 0) break;
		sum++;
	}
	if (sum == 3) isSameKind = true;

	return isSameKind;
}
