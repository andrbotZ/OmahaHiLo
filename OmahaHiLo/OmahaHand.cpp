#include "OmahaHand.h"

OmahaHand::OmahaHand(string playerName)
{
	name = playerName;
}

void OmahaHand::DealCards(string cardsChain)
{
	cmatch cardMatch;
	regex cardARegex("([cdhsAKQJT0123456789]{2,3})");

    for (sregex_iterator it = sregex_iterator(cardsChain.begin(), cardsChain.end(), cardARegex); it != sregex_iterator(); it++) {
        smatch match;
        match = *it;
		
		Card card{ match.str() };
		cards.push_back(card);
    }
	SortCards();
}

void OmahaHand::CombineCards(vector<Card> boardCards)
{
	vector<Card> tempCards;
	for (int i1 = 0; i1 < cards.size() - 1; i1++) {
		
		tempCards.push_back(cards[i1]);
		for (int i2 = i1 + 1; i2 < cards.size(); i2++) {
			tempCards.push_back(cards[i2]);
			for (int j1 = 0; j1 < boardCards.size() - 2; j1++) {
				tempCards.push_back(boardCards[j1]);
				for (int j2 = j1 + 1; j2 < boardCards.size() - 1; j2++) {
					tempCards.push_back(boardCards[j2]);
					for (int j3 = j2 + 1; j3 < boardCards.size(); j3++) {
						tempCards.push_back(boardCards[j3]);
						rank.UpdateHighest(tempCards);
						rank.UpdateLowest(tempCards);
						tempCards.pop_back();
					}
					tempCards.pop_back();
				}
				tempCards.pop_back();
			}
			tempCards.pop_back();
		}
		tempCards.pop_back();
	}

}

void OmahaHand::SortCards()
{
	for (int i = 0; i < cards.size() - 1; i ++) {
		for (int j = 0; j < cards.size() - i - 1; j++) {
			if (cards[j].value < cards[j + 1].value) {
				Card tempCard { cards[j].rank + cards[j].suit };
				cards[j] = cards[j + 1];
				cards[j + 1] = tempCard;
			}
		}

	}
}


