#pragma once
#include <vector>
#include <Regex>
#include "Card.h"

class HandRank
{
protected:
	cmatch _suitMatch;
	regex _suitRegex;

public:
	virtual bool Validate(vector<Card> cards) = 0;
};

