#pragma once
#include <vector>
#include <Regex>
#include "Card.h"

class Straight  
{
	private:
	cmatch _suitMatch;
	regex _suitRegex{ "cdhs" };
	
	public:
		bool Validate(vector<Card> cards);
};

