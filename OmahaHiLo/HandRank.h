#pragma once
#include <vector>
#include <Regex>
#include "Card.h"

class HandRank
{
protected:
	cmatch _suitMatch;
	regex _suitRegex;
	string suit;
	string rank;
	

protected:
	void SetSuitAndRank(vector<Card> cards) ;
	bool VerifySameRank(int num);
	bool VerifySameSuit(int num);
	bool VerifyAllDifferentSuits();

public:
	virtual ~HandRank() = default;
	virtual bool Validate(vector<Card> cards) = 0;
	
};

