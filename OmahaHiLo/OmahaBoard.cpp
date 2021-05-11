#include "OmahaBoard.h"
#include "OmahaGame.h"


void OmahaBoard::DealCards(list<string> data)
{
	vector<string> _players = { "HandA", "HandB" };
	string _board = "Board";
	for (list<string>::iterator _line = data.begin(); _line != data.end(); ++_line) {
		OmahaGame game(_players,_board);
		string data = *_line;
		game.DealCards(data);
		games.push_back(game);
	}
}

void OmahaBoard::Play()
{
	for (vector<OmahaGame>::iterator _game_iterator = games.begin(); _game_iterator != games.end(); ++_game_iterator) {
		OmahaGame game = *_game_iterator;
		game.Play();
	
	}

}

vector<string> OmahaBoard::PrintResults()
{
	vector<string> gamesResults;

	for (vector<OmahaGame>::iterator _game_iterator = games.begin(); _game_iterator != games.end(); ++_game_iterator) {
		OmahaGame game = *_game_iterator;
		string result = game.PrintResult();
		gamesResults.push_back(result);

	}
	return gamesResults;
}


