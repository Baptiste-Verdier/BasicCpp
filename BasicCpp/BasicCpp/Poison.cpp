#include "Poison.h"
Poison::Poison() :
	Items { },
	mPoisonDamage{ 0 },
	mPoisonChance{ 0 }
{	}

Poison::Poison(string name, int poisonDamage, int poisonChance, int price, string type) :
	Items{name, price},
	mPoisonDamage{ poisonDamage },
	mPoisonChance{ poisonChance },
	mType{type}
	{	}