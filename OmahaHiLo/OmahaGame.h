#pragma once
#include <string>
#include<map>
#include "OmahaHand.h"
#include <vector>
#include <regex>

using namespace std;

class OmahaGame {

	private:
		map<string,OmahaHand> _players;
		OmahaHand _board;

	public:
		OmahaGame(vector<string> playersNames, string boardName);
		void FlopAction(string data);
};
