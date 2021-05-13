
#include "Straight.h"
#include <iostream>


bool Straight::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifyAllDifferentSuits()) {
		if (VerifyAllCardsConsecutive(cards)) {
			return true;
		}
		
	}

	return false;
}

 

