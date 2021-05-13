#include "FullHouse.h"
#include <iostream>


bool FullHouse::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifySameRank(3,2)) {
		return true;
	}

	return false;
}
