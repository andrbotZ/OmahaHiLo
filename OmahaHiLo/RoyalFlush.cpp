#include "RoyalFlush.h"


bool RoyalFlush::Validate(vector<Card> cards)
{
	string suit;
	string rank;

	for (int i = 0; i < cards.size(); i++)
	{
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	 }
	if (regex_search(suit.c_str(), _suitMatch, _suitRegex)) {
		if (rank.compare("AKQJ10") == 0) {
			return true;
		}
	}

	return false;
}
