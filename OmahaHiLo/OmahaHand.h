#pragma once
#include<string>
#include <vector>
#include"Card.h"
#include <Regex>
#include "Rank.h"

using namespace std;

class OmahaHand {

	public:
		string name;
		vector<Card> cards;
		Rank rank;


	public:
		OmahaHand() {};
		OmahaHand(string playerName);
		void DealCards(string cards);
		void CombineCards(vector<Card> cards);
};
