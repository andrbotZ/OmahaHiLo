#include "OmahaGame.h"


OmahaGame::OmahaGame(vector<string> playersNames, string boardName)
{
 // HandA:Ac - Kd - Jd - 3d HandB : 5c - 5d - 6c - 7d Board : Ah - Kh - 5s - 2s - Qd


	_board = OmahaHand{ boardName };
	for (vector<string>::iterator it = playersNames.begin(); it != playersNames.end(); ++it) {
		string _player = *it;
		OmahaHand hand{ _player };
		_players.insert({ _player, hand });
	}
	
	
	
}

void OmahaGame::FlopAction(string data)
{
	for (map<string, OmahaHand>::iterator it = _players.begin(); it != _players.end(); ++it) {
		OmahaHand player = it -> second;
		cmatch handAMatch;
		regex handARegex (player.name + ":(\\S*)");
		bool find = regex_search(data.c_str(), handAMatch, handARegex);
		player.setCards(handAMatch[1].str());
	}
			
}
