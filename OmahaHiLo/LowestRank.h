#pragma once

#include <vector>
#include <Regex>
#include "HandRank.h"
#include "Card.h"

class LowestRank : public HandRank
{
public:
	int result;
public:
	bool Validate(vector<Card> cards);

};

