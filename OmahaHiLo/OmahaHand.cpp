#include "OmahaHand.h"

OmahaHand::OmahaHand(string playerName)
{
	name = playerName;
}

void OmahaHand::DealCards(string cardsChain)
{
	cmatch cardMatch;
	regex cardARegex("([cdhsAKQJ0123456789]{2,3})");

    for (sregex_iterator it = sregex_iterator(cardsChain.begin(), cardsChain.end(), cardARegex); it != sregex_iterator(); it++) {
        smatch match;
        match = *it;
		
		Card card{ match.str() };
		cards.push_back(card);
    }
	rank.Update(cards);
}

void OmahaHand::CombineCards(vector<Card> cards)
{

}
