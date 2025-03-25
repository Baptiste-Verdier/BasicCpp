#pragma once
#include <iostream>
#include <string>
using std::string;

class BodyPart
{
private:
	string name;
	int poisonResistance;
	int life;
	int attackMod;
	int healingChance;
	int attackChance;
	bool isPoisoned;

public: 
int attackBasic(int dodgeChance, int attackMod, int attackChance) const;
int poisonStatus(int poisonResistance, int poisonDamage, bool isPoisoned, int healingChance);
void displayInfo(string name, int life, int attackMod, int attackChance, int poisonResistance, int healingChance, int dodgeChance, bool isPoisoned) const;

};

