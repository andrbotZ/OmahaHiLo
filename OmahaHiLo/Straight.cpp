
#include "Straight.h"
#include <iostream>


bool Straight::Validate(vector<Card> cards)
{
	SetSuitAndRank(cards);
	if (VerifyAllDifferentSuits()) {
		return true;
	}

	return false;
}

//bool Straight::Validate(vector<Card> cards)
//{
//	string suit;
//	string rank;
//	bool isSameKind{ false };
//
//	for (unsigned int i = 0; i < cards.size(); i++)
//	{
//		suit = suit + cards[i].suit;
//		rank = rank + cards[i].rank;
//	}
//
//	int sum = 0;
//	for (unsigned int i = 0; i < cards.size() - 1; i++)
//	{
//		char current = suit.at(i);
//		sum = sum + current;
//
//	}
//
//	if (sum == 418) {
//
//
//	}
//
//	return false;
//
//}

