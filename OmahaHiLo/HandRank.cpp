#include"HandRank.h"
#include <iostream>

void HandRank:: SetSuitAndRank(vector<Card> cards) {
	for (unsigned int i = 0; i < cards.size(); i++){
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}
}

//bool HandRank::VerifySameRank(int num)
//{
//	int counter = 0;
//	bool noSameRank = false;
//	if (num == 1) noSameRank = true;
//
//	if (num <= rank.length()) {
//
//		for (unsigned int i = 0; i < rank.length() - num + 1; i++) {
//			
//			counter = 1;	
//			char ch1 = rank.at(i);
//
//			for (unsigned int j = i + 1; j < rank.length() - num + 2; j++) {
//				for (unsigned int k = j; k < j + num - 1; k++) {
//					char ch2 = rank.at(k);
//					if (ch2 == ch1) {
//						if (noSameRank) {
//							return false;
//						}
//						counter++;
//					}
//
//				}
//		
//				if (!noSameRank && counter == num ) {
//					return true;
//				}
//				counter = 1;
//
//			}
//			
//		}
//		if (noSameRank && counter == 1) {
//			return true;
//		}
//	}
//
//	return false;
//
//}
bool HandRank::VerifyNoSameRank()
{
		for (unsigned int i = 0; i < rank.length() - 1 ; i++) {

			char ch1 = rank.at(i);

			for (unsigned int j = i + 1; j < rank.length(); j++) {
				
				char ch2 = rank.at(j);
				if (ch2 == ch1) {
					return false;
				}
			}
		}

	return true;

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
	int sum = 'c' + 'h' + 'd' + 's';
	
	if (rank.compare("432AA") == 0) {

		string ff;
	}
	int sumSuit = 0;
	vector<int> vectorA;
	for (unsigned int i = 0; i < rank.length(); i++) {
	
		

		if (rank[i] == 'A') {
			vectorA.push_back(suit.at(i));
		}

		sumSuit = sumSuit + suit.at(i);
		 


		}
	if (vectorA.size() != 0) {
		for (int i = 0; i < vectorA.size(); i++) {
			int test = sumSuit - vectorA[i];
			if (test == sum) return true;
		}
	}

	return false;
}

 
bool HandRank::VerifyAllCardsConsecutive(vector<Card> cards)
{
		
	if (rank[0] == 'A') {
		if (rank.compare("AKQJT") == 0) return true;
		else {
			int sum = rank[1] + rank[2] + rank[3] + rank[4] - '2' - '3' - '4' - '5';
			if (sum == 0) {
				return true;
			}
		}
	}

	else {
		int diff = 0;
		for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
			Card card = *it;
			
			if (diff == 0) {
				diff = diff + card.value;
			}
			else {
				diff = diff - card.value;
				if (diff != 1) return false;
			}
		}
		if (diff == 1) return true;

	}
	return false;
}

int HandRank::GetHighestRankCard(vector<Card> cards)
{
	int highest = 0;
	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
		Card card = *it;
		int value = card.value;

		if (value > highest) {
			highest = value;
		}

	}
	return highest;
}

