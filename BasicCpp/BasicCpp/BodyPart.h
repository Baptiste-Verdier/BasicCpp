#pragma once
#include <string>
#include "Poison.h"
using std::string;

class BodyPart
{
private :
	
	int const mMaxLife;
	int mAttackMod;
	static int const mBaseHealingChance;
	int mHealingChance;
	int mAttackChance;

public: 
	BodyPart();
	BodyPart(string name, int poisonResistance, int maxLife, int attackMod, int attackChance);
	string mName;
	int mPoisonResistance;
	int mLife;
	bool mIsPoisoned;
	bool mCanPlay;

	int attackBasic(int dodgeChance) const;
	int poisonStatus(Poison* poison);
	void displayInfo(int dodgeChance) const;

};

