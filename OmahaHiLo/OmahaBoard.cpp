#include "OmahaBoard.h"
#include "OmahaGame.h"


void OmahaBoard::FlopAction(list<string> data)
{
	for (list<string>::iterator _line = data.begin(); _line != data.end(); ++_line) {
		OmahaGame game(*_line);
	}
}
