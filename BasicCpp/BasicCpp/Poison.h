#pragma once
#include "Items.h"
#include <string>
using std::string;

class Poison: public Items
{

public :
	Poison();
	Poison(string name, int poisonDamage, int poisonChance, int price, string type);
	string name;
	int   mPoisonDamage;
	int const mPoisonChance;
	string mType;
	

};

