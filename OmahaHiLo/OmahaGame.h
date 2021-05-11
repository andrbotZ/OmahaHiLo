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


	public:
		OmahaGame(vector<string> playersNames, string boardName);
		void DealCards(string data);
		void Play();
};
