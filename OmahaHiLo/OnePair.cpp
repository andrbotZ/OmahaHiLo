#include "OnePair.h"
 
bool OnePair::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifySameRank(2)) {
		return true;
	}

	return false;
}
