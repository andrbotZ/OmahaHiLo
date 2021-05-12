#include "ThreeOfKind.h"
#include <iostream>


bool ThreeOfKind::Validate(vector<Card> cards)
{
	string suit;
	string rank;
	bool isSameKind{ false };

	for (unsigned int i = 0; i < cards.size(); i++)
	{
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}

	int sum = 0;
 
	for (unsigned int i = 0; i < cards.size() - 1; i++)
	{
		if ((cards[i].value - cards[i + 1].value) == 0)
		{
			sum++;
		}else{
			if (sum < 2) {
				sum = 0;
			}
		}

	}
	if (sum == 2) {
		isSameKind = true;
	}

	return isSameKind;
}
