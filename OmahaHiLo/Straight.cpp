
#include "Straight.h"
#include <iostream>


bool Straight::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (!VerifySameRank(5)) {
		if (VerifyAllCardsConsecutive(cards)) {
			return true;
		}
		
	}

	return false;
}

 

