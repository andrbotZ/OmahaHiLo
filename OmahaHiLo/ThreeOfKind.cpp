#include "ThreeOfKind.h"
#include <iostream>


bool ThreeOfKind::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifySameRank(3)) {
		return true;
	}

	return false;
}
