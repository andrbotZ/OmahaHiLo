#include "Card.h"
#include <iostream>
#include <sstream>

Card::Card(string card)
{
	cmatch suitMatch;
	cmatch rankMatch;
	regex_search(card.c_str(), suitMatch, suitRegex);
	regex_search(card.c_str(), rankMatch, rankRegex);

	suit = suitMatch.str();
	rank = rankMatch.str();

	if (rank.compare("A") == 0) value = 100;
	else if (rank.compare("K") == 0) value = 13;
	else if (rank.compare("Q") == 0) value = 12;
	else if (rank.compare("J") == 0) value = 11;
	else {
		stringstream strValue(rank);
		strValue >> value;
	}
  
}
