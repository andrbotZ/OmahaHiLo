#include "LowestRank.h"
#include <iostream>
#include<cmath>

bool LowestRank::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifyNoSameRank()) {
		if (GetHighestRankCard(cards) < 9) {
			int sum = 0;
			int j = cards.size();;
			for (int i = 0; i < cards.size(); i++) {
				if (cards[i].value == 1) {
					sum = sum + 1;
				}
				else {
					int exp = cards.size() - i - 1;
					int power = pow(10, exp);
					sum = sum + cards[i].value * power;
					j--;
				}
			}
			result = sum;
			return true;
		 }
	}

	return false;
}
 
