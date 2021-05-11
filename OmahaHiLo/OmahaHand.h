#pragma once
#include<string>
#include <vector>
#include"Card.h"
#include <Regex>

using namespace std;

class OmahaHand {

	public:
		string name;
		vector<Card> cards;


	public:
		OmahaHand() {};
		OmahaHand(string playerName);
		void setCards(string cards);
};
