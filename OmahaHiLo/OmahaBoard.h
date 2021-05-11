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
		void FlopAction(list<string> data);
		void Play();
		void PrintResults();
		void SaveResultsInFile(string path);
};