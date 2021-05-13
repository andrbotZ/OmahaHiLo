#include "OmahaGame.h"
#include <iostream>


OmahaGame::OmahaGame(vector<string> playersNames, string boardName)
{
	_board = OmahaHand{ boardName };
	for (vector<string>::iterator it = playersNames.begin(); it != playersNames.end(); ++it) {
		string _player = *it;
		OmahaHand hand{ _player };
		_players.insert({ _player, hand });
	}
	
	
	
}

void OmahaGame::DealCards(string data)
{
	rawData = data;
	for (map<string, OmahaHand>::iterator it = _players.begin(); it != _players.end(); ++it) {
		OmahaHand player = it -> second;
		cmatch handAMatch;
		regex handARegex (player.name + ":(\\S*)");
		bool find = regex_search(data.c_str(), handAMatch, handARegex);
		player.DealCards(handAMatch[1].str());
		_players.at(player.name) = player;
	}

	cmatch handAMatch;
	regex handARegex(_board.name + ":(\\S*)");
	bool find = regex_search(data.c_str(), handAMatch, handARegex);
	_board.DealCards(handAMatch[1].str());
}

void OmahaGame::Play() {
	for (map<string, OmahaHand>::iterator it = _players.begin(); it != _players.end(); ++it) {
		//OmahaHand player = it->second;
	
		it->second.CombineCards(_board.cards);

 
		int winnerNum = winnerHighestRank.rank.CompareHighestRank(it->second.rank.HighestRank);

		if (winnerNum == 2) winnerHighestRank = it->second;

		if (winnerLowestRank.rank.LowestRankValue == 0) {
			winnerLowestRank = it->second;
		}
		else {
			winnerNum = winnerLowestRank.rank.CompareLowestRank(it->second.rank.LowestRankValue);

			if (winnerNum == 2) winnerLowestRank = it->second;
		}


		_players.at(it->second.name) = it->second;

	}
 
}

string OmahaGame::PrintResult() {
	std::cout  << '\n';
	std::cout << rawData << '\n';
	string result = "=>  " + winnerHighestRank.name + " wins Hi (" + winnerHighestRank.rank.GetHighestRank() + ") ; " + winnerLowestRank.name + " wins Lo ( " + winnerLowestRank.rank.GetLowestRank() +" )";
	std::cout << result << '\n';
	return result;
}

 
