#include "LowestRank.h"

int LowestRank::Convert(vector<Card> cards)
{
	string suit;
	string rank;
 
	bool isSameKind{ false };

	for (unsigned int i = 0; i < cards.size(); i++)
	{
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
 
	}
	int value = 0;
	if (!regex_search(rank.c_str(), _rankMatch, _rankRegex)) {

		for (unsigned int i = 0; i < rank.length() - 1; i++)
		{
			char ch1 = rank.at(i);
			char ch2 = rank.at(i + 1);
			if (ch1 == ch2) {
				return value;
			}
		}

		stringstream ss;
		if (rank.at(0) == 'A') {
			string temp = rank.substr(1, rank.length());
			ss << temp;
			ss >> value;
			value = value * 10 + 1;
		}

		
		
		}

	return value;
}

 
