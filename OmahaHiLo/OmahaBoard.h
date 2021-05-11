#pragma once

#include<list>
#include<string>
#include<vector>
#include "OmahaGame.h"

using namespace std;

class OmahaBoard {

	public:
		vector<OmahaGame> games;

	public:
		void DealCards(list<string> data);
		void Play();
		vector<string> PrintResults();

};