#include "Card.h"


Card::Card(string card)
{
	cmatch suitMatch;
	cmatch rankMatch;
	regex_search(card.c_str(), suitMatch, suitRegex);
	regex_search(card.c_str(), rankMatch, rankRegex);

	suit = suitMatch.str();
	rank = rankMatch.str();
}
