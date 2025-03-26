#include <iostream>
#include <string>
#include "BodyPart.h"
#include "Poison.h"

using std::cout;



int const BodyPart::mBaseHealingChance = 10;

BodyPart::BodyPart(string name, int poisonResistance, int maxLife, int attackMod, int attackChance) :
    
    
    mName{ name },
    mPoisonResistance{ poisonResistance },
    mMaxLife{ maxLife },
    mLife{ maxLife },
    mAttackMod(attackMod),
    mAttackChance(attackChance),
    mIsPoisoned{ false },
    mCanPlay{true}
{
    mHealingChance = mBaseHealingChance;
}
BodyPart::BodyPart() :
    mName{ "default" },
    mPoisonResistance{75},
    mAttackMod{1},
    mAttackChance{50},
    mIsPoisoned{ false },
    mCanPlay{ true },
    mMaxLife{30}
{
    mLife = mMaxLife;
    mHealingChance = mBaseHealingChance;
}

    
   
int BodyPart::attackBasic(int dodgeChance) const
{
    if ((rand() % 100) + 1 <= mAttackChance - dodgeChance)
    {
        cout << "The beast has struck you !";
        return (rand() % 5) + 1 + mAttackMod;
    }
    else { cout << "You avoid the beasts fang"; return 0; }
}

int BodyPart::poisonStatus(Poison poison) 
{
    if (mIsPoisoned || (rand() % 100) + 1 >= poison.mPoisonChance - mPoisonResistance)
    {
        cout << "The target suffers from poisoning\n";
        mIsPoisoned = true;
        if (poison.mType == "Paralysis") { mCanPlay = false; }
        if (rand() % 100 + 1 <= mHealingChance) 
            {
            cout << "But heals from the poison afterwards";
            mHealingChance = mBaseHealingChance;
            mIsPoisoned = false;
            }
        else { mHealingChance += 5; }
        return poison.mPoisonDamage;
    }
    else { cout << "You failed to poison the target"; return 0; }
}

void BodyPart::displayInfo(int dodgeChance) const 
{
    cout << mName + "\n";
    cout << "It has " << mLife <<" hit points remaining" << "\n";
    cout << "It has a "; if (mAttackChance - dodgeChance <= 0) { cout << 0; } else { cout << mAttackChance - dodgeChance; } cout <<"% chance to hit you\n";
    cout << "It can deal between " <<mAttackMod << " and " << mAttackMod +5 << " damage\n";

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
