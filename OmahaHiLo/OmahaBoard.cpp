#include "OmahaBoard.h"
#include "OmahaGame.h"


void OmahaBoard::FlopAction(list<string> data)
{
	vector<string> _players = { "HandA", "HandB" };
	string _board = "Board";
	for (list<string>::iterator _line = data.begin(); _line != data.end(); ++_line) {
		OmahaGame game(_players,_board);
		string data = *_line;
		game.FlopAction(data);
	}
}
