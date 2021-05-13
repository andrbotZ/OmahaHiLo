#include"HandRank.h"
#include <iostream>
#include <map>

void HandRank:: SetSuitAndRank(vector<Card> cards) {
	for (unsigned int i = 0; i < cards.size(); i++){
		suit = suit + cards[i].suit;
		rank = rank + cards[i].rank;
	}
}

 
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

bool HandRank::VerifySameRank(int num1, int num2)
{
	map<char, int> dublicates;
	for (int i = 0; i < rank.length(); i++) {
		dublicates[rank[i]]++;
	}

	if (dublicates.size() == 2) {

		int sum = 0;
		for (auto it : dublicates) {
			if (it.second > 1)
				sum = sum + it.second;
		}
		if (sum ==(num1 + num2)) return true;
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
 
	if (rank[4] == 'A') {
		if (rank.compare("KQJTA") == 0) return true;
		else {
			if (rank.compare("5432A") == 0) return true;
		}
	}

	else {
		int diff = 0;

		for (int i = 0; i < cards.size() - 1; i++) {
			

			if ((cards[i].value - cards[i + 1].value) == 1) {
				diff++;
			}

			else { return false; }
		}

		if (diff == 4) return true;

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

