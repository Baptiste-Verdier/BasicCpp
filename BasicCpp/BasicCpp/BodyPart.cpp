#include <iostream>
#include <string>
#include "BodyPart.h"

using std::cout;

BodyPart::BodyPart() :
    mName{ "Dog" },
    mPoisonResistance{ 50 },
    mAttackMod{ 1 },
    mAttackChance{ 50 },
    mIsPoisoned{ false },
    mHealingChance{ 10 },
    mMaxLife(10) {mLife = mMaxLife;}
    
   
int BodyPart::attackBasic(int dodgeChance) const
{
    if ( mAttackChance - dodgeChance <= 0) 
    {
        cout << "You avoid the beasts fang"; return 0;
       
    }
    else if ((rand() % 100) + 1 >= mAttackChance - dodgeChance)
    {
        cout << "The beast has struck you !";
        return (rand() % 5) + 1 + mAttackMod;
    }
    else { cout << "You avoid the beasts fang"; return 0; }
}

int BodyPart::poisonStatus( int poisonDamage) 
{
    if (mIsPoisoned || (rand() % 100) + 1 >= mPoisonResistance)
    {
        cout << "The target suffers from poisoning\n";
        mIsPoisoned = true;
        if (rand() % 100 + 1 <= mHealingChance) 
            {
            cout << "But heals from the poison afterwards";
            mHealingChance = 10;
            mIsPoisoned = false;
            }
        else { mHealingChance += 5; }
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
