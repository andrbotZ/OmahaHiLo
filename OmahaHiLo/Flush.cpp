#include "Flush.h"

bool Flush::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifySameSuit(5)) {
		return true;
	}

	return false;
}
