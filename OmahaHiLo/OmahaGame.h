#pragma once
#include <string>
#include<map>
#include "OmahaHand.h"
#include <vector>
#include <regex>
#include "Rank.h"

using namespace std;

class OmahaGame {

	private:
		map<string,OmahaHand> _players;
		OmahaHand _board;
		Rank _rank;
	private:
		int getHighWinner(OmahaHand player1, OmahaHand player2);
		int getLowWinner(OmahaHand player1, OmahaHand player2);
	public:
		string rawData;
		OmahaHand winnerHighestRank;
		OmahaHand winnerLowestRank;
	public:
		OmahaGame(vector<string> playersNames, string boardName);
		void DealCards(string data);
		void Play();
		string PrintResult();
};
