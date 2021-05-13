#pragma once
#include <string>
#include<Regex>

using namespace std;

class Card
{
	private:
		regex suitRegex {"([cdhs])"};
		regex rankRegex { "([AKQJT0123456789]{1,2})" };
		 

	public:
		string suit;
		string rank;
		int value;

	public:
		Card(string card);
};

