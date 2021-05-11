#pragma once
#include <string>
#include<map>
#include "OmahaHand.h"
#include <regex>

using namespace std;

class OmahaGame {

	private:
		map<string,OmahaHand> _players;
		OmahaHand _board;

	public:
		OmahaGame(string playersNames[], string boardName);
		void FlopAction(string data);
};
