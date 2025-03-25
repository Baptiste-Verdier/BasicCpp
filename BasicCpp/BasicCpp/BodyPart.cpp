#include <iostream>
#include <string>
#include "BodyPart.h"

using std::cout;

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

void BodyPart::displayInfo(string name, int life, int attackMod, int attackChance, int poisonResistance, int healingChance, int dodgeChance, bool isPoisoned) const 
{
    cout << name + "\n";
    cout << "It has " << life <<" hit points remaining" << "\n";
    cout << "It has a "; if (attackChance - dodgeChance <= 0) { cout << 0; } else { cout << attackChance - dodgeChance; } cout <<"% chance to hit you\n";
    cout << "It can deal between " <<attackMod << " and " << attackMod +5 << " damage\n";
    if (isPoisoned) 
    { 
        cout << "It has a " << healingChance << "% to cure itself from the poison next turn\n";
        cout << "It is poisoned\n"; 
    } 
    else 
    { 
        cout << "It has a "<< poisonResistance << "% chance to resist being poisonned\n";
        cout << "It is NOT poisoned\n";
    }
}
