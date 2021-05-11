#include "OmahaGame.h"


OmahaGame::OmahaGame(string playersNames[], string boardName)
{
 // HandA:Ac - Kd - Jd - 3d HandB : 5c - 5d - 6c - 7d Board : Ah - Kh - 5s - 2s - Qd


	_board = OmahaHand{ boardName };
	for (int i = 0; i < sizeof(playersNames); i++) {
		string _player = playersNames[i];
		OmahaHand hand{ _player };
		_players.insert({ _player, hand });
	}
	
	
	
}

void OmahaGame::FlopAction(string data)
{
	for (std::map<string, OmahaHand>::iterator it = _players.begin(); it != _players.end(); ++it) {
		OmahaHand player = it -> second;
		cmatch handAMatch;
		regex handARegex(player.name + ":(\S*)");
		regex_match(data.c_str(), handAMatch, handARegex);
		
	}
		
		
		
}
