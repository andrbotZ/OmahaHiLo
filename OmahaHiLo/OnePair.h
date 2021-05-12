#pragma once
#include <vector>
#include <Regex>
#include "HandRank.h"
#include "Card.h"

class OnePair : public HandRank
{
public:
	bool Validate(vector<Card> cards);
};
