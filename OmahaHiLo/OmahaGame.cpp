#include "OmahaGame.h"


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
		OmahaHand player = it->second;
	
		player.CombineCards(_board.cards);

		_players.at(player.name) = player;
	}
}
