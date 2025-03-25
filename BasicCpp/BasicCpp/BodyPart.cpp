#include <iostream>
#include <string>
#include "BodyPart.h"

using std::cout;

BodyPart::BodyPart() :
    mName{"Dog"},
    mPoisonResistance{ 50 },
    mAttackMod{ 1 },
    mHealingChance{ 10 },
    mAttackChance{ 50 },
    mIsPoisoned{ false },
    mMaxLife(10) {
    mLife = mMaxLife;}
   
int BodyPart::numberKilled{ 1 };

int BodyPart::attackBasic(int dodgeChance, int attackMod, int attackChance) const
{
    if ( attackChance - dodgeChance <= 0) 
    {
        cout << "You avoid the beasts fang"; return 0;
       
    }
    else if ((rand() % 100) + 1 >= attackChance - dodgeChance)
    {
        cout << "The beast has struck you !";
        return (rand() % 5) + 1 + attackMod;
    }
    else { cout << "You avoid the beasts fang"; return 0; }
}

int BodyPart::poisonStatus(int poisonResistance, int poisonDamage, bool isPoisoned, int healingChance) 
{
    if (isPoisoned || (rand() % 100) + 1 >= poisonResistance)
    {
        cout << "The target suffers from poisoning\n";
        isPoisoned = true;
        if (rand() % 100 + 1 <= healingChance) 
            {
            cout << "But heals from the poison afterwards";
            isPoisoned = false;
            }
        else { healingChance += 15; }
        return poisonDamage;
    }
    else { cout << "You failed to poison the target"; return 0; }
}

void BodyPart::displayInfo(int dodgeChance) const 
{
    cout << mName + "\n";
    cout << "It has " << mLife <<" hit points remaining" << "\n";
    cout << "It has a "; if (mAttackChance - dodgeChance <= 0) { cout << 0; } else { cout << mAttackChance - dodgeChance; } cout <<"% chance to hit you\n";
    cout << "It can deal between " <<mAttackMod << " and " << mAttackMod +5 << " damage\n";
    cout << numberKilled << "\n";
    numberKilled++;
    if (mIsPoisoned) 
    { 
        cout << "It has a " << mHealingChance << "% to cure itself from the poison next turn\n";
        cout << "It is poisoned\n"; 
    } 
    else 
    { 
        cout << "It has a "<< mPoisonResistance << "% chance to resist being poisonned\n";
        cout << "It is NOT poisoned\n";
    }
}
