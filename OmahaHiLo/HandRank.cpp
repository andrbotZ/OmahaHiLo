#include"HandRank.h"

void HandRank:: SetSuitAndRank(vector<Card> cards) {
	for (unsigned int i = 0; i < cards.size(); i++){
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}
}

bool HandRank::VerifySameRank(int num)
{

	int counter = 0;
	if (num < rank.length()) {
		int testrank = rank.length() - num + 1;
		for (unsigned int i = 0; i < rank.length() - num + 1; i++) {
			counter = 1;
			char ch1 = rank.at(i);

			for (unsigned int j = i + 1; j < rank.length() - num + 2; j++) {
				for (unsigned int k = j; k < j + num - 1; k++) {
					char ch2 = rank.at(k);
					if (ch2 == ch1) {

						counter++;
					}

				}
				if (counter == 3) {
					return true;
				}
				counter = 1;


			}
		}
	}

	return false;
	 
}

