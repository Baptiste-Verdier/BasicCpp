#pragma once
#include <iostream>
#include <string>
using std::string;

class BodyPart
{
public: 
BodyPart();
	


	string mName;
	int mPoisonResistance;
	int mLife;
	int  mMaxLife;
	int mAttackMod;
	int mHealingChance;
	int mAttackChance;
	bool mIsPoisoned;
	static int numberKilled;

int attackBasic(int dodgeChance, int attackMod, int attackChance) const;
int poisonStatus(int poisonResistance, int poisonDamage, bool isPoisoned, int healingChance);
void displayInfo(int dodgeChance) const;

};

