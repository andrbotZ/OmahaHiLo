#include "OmahaGame.h"


OmahaGame::OmahaGame(string input)
{
 // HandA:Ac - Kd - Jd - 3d HandB : 5c - 5d - 6c - 7d Board : Ah - Kh - 5s - 2s - Qd


	cmatch handAMatch;
	regex handARegex ("HandA:([cdhsAKQJ0123456789]{2}{3}){4}");
	regex_match(input.c_str(),handAMatch, handARegex);
	
}
