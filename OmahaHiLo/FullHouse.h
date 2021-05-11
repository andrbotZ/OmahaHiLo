#pragma once
#include <vector>
#include <Regex>
#include "Card.h"

class FullHouse
{
private:
	cmatch _suitMatch;
	regex _suitRegex{ "ccccc|ddddd|hhhhh|sssss" };

public:
	bool Validate(vector<Card> cards);
};

