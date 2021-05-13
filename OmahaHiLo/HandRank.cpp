#include"HandRank.h"
#include <iostream>

void HandRank:: SetSuitAndRank(vector<Card> cards) {
	for (unsigned int i = 0; i < cards.size(); i++){
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}
}

bool HandRank::VerifySameRank(int num)
{

	int counter = 0;
	if (num <= rank.length()) {
	 
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
				if (counter == num) {
					return true;
				}
				counter = 1;


			}
		}
	}

	return false;
	 
}

bool HandRank::VerifySameSuit(int num)
{
	int counter = 0;
	if (num <= suit.length()) {
		 
		for (unsigned int i = 0; i < suit.length() - num + 1; i++) {
			counter = 1;
			char ch1 = suit.at(i);

			for (unsigned int j = i + 1; j < suit.length() - num + 2; j++) {
				for (unsigned int k = j; k < j + num - 1; k++) {
					char ch2 = suit.at(k);
					if (ch2 == ch1) {

						counter++;
					}

				}
				if (counter == num) {
					return true;
				}
				counter = 1;


			}
		}
	}
	return false;
}

bool HandRank::VerifyAllDifferentSuits()
{	 
 
		for (unsigned int i = 0; i < suit.length() - 1; i++) {

			char ch1 = suit.at(i);

			for (unsigned int j = i + 1; j < suit.length() ; j++) {
				 
					char ch2 = suit.at(j);
					if (ch2 == ch1) return false;				 
			}
		}

	return true;
}

bool HandRank::VerifyAllCardsConsecutive()
{

	for (unsigned int i = 0; i < suit.length() - 1; i++) {

		char ch1 = suit.at(i);

		for (unsigned int j = i + 1; j < suit.length(); j++) {

			char ch2 = suit.at(j);
			if (ch2 == ch1) return false;
		}
	}

	return true;
}

