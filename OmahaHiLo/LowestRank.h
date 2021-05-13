#pragma once
#include <vector>
#include <Regex>
#include "Card.h"
#include <sstream>
class LowestRank
{
	private:
		cmatch _rankMatch;
		regex _rankRegex{ "[KQJT9]" };

	public:
		int Convert(vector<Card> cards);
};

