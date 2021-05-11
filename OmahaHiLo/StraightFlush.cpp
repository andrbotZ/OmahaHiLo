#include "StraightFlush.h"

bool StraightFlush::Validate(vector<Card> cards)
{
	string suit;
	string rank;
	bool isSequantial{ false };

	for (int i = 0; i < cards.size(); i++)
	{
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}
 
	if (regex_search(suit.c_str(), _suitMatch, _suitRegex)) {
		int sum = 0;
		for (int i = 0; i < cards.size() - 1; i++)
		{
			if (cards[i].value - cards[i + 1].value != 1) break;
			sum++;
		}
		if (sum == 4) isSequantial = true;
	}
	return isSequantial;
}
