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
	int const  mMaxLife;
	int mAttackMod;
	int  mHealingChance;
	int mAttackChance;
	bool mIsPoisoned;


int attackBasic(int dodgeChance) const;
int poisonStatus(int poisonDamage);
void displayInfo(int dodgeChance) const;

};

