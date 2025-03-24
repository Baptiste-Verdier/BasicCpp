// BasicCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::cout;
using std::cin;
using std::string;
using std::map;
void lineBreak() { cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n"; }

int attackBasic(int dodgeChance) 
{
    if ((rand() % 100) + 1 >= dodgeChance)
    {
        cout << "The beast has struck you !";
        return (rand() % 5) + 1;
    }
    else { cout << "You avoid the beasts fang"; return 0; }
    
}

bool poisonning(int poisonChance)
{
    if ((rand()%100)+1 <= poisonChance)
        {
            cout << "The target has been successfully poisoned";
            return true;
        } 
    else {cout << "You failed to poison the target" ; return false; }
}

int weaken(int poisonChance) 
{
    poisonChance += rand() % 30 + 11;
    return poisonChance;
}


int main()
{
    // MAIN PROJECT
    srand(time(NULL));
    int poisonChance = 10;
    int poisonDamage = 1;
    int playerLife = 20;
    int wolfLife = 20;
    int choice = 0;
    int dodgeChance = 10;
    bool isPoisonned = false;

    cout << "You're a peaceful plague doctor on a path to the woods when you encounter a wolf, you must fight ";
    lineBreak();
    while (wolfLife >= 0 && playerLife >= 0)
    {
        dodgeChance = 10;
        cout << "You have " << playerLife << " life remaining\n";
        cout << "The wolf has " << wolfLife << " life remaining\n";
        cout << "Your poison has a potency of " << poisonDamage << "\n";
        if (!isPoisonned) { cout << "The beast has a " << poisonChance << "% chance of being poisoned\n"; }
        cout << "The beast is "; if (!isPoisonned) { cout << "NOT "; } cout << "poisonned\n";
        lineBreak();

        cout << "What will you do ?\n1 - Attempt to poison the beast?\n2 - Lower the beast resistance ?\n3 - Increase your poison's potency ? \n4 - Dodge ?\n";
        do {
            cin >> choice;
            switch (choice)
            {
            case 1:
                lineBreak();
                isPoisonned = poisonning(poisonChance);
                cout << "\n";
                break;
            case 2:
                lineBreak();
               cout<<"You increase the chance of your poison taking hold\n";
               poisonChance = weaken(poisonChance);
                cout << "\n";
                break;
            case 3:
                lineBreak();
                poisonDamage++;
                cout << "Your poison will kill the beast faster !\n";
                break;
            case 4:
                lineBreak();
                dodgeChance += 65;
                cout << "You decrease the chance of the beast striking you\n";
                break;
            default:
                cout << "Try again PUNK \n";
                choice = 0;
            }
        } while (choice == 0);

        playerLife -= attackBasic(dodgeChance);
        if (isPoisonned) {wolfLife -= poisonDamage;}
        lineBreak();
    }

    if (wolfLife <= 0) { cout << "You're victorious !"; }
    else if (playerLife <= 0) { cout << "Oupsy, you died"; }

    return 0;

    // EXERCISES
   /* string narratorName = "The Great";

    cout << "Hello, I am " + narratorName + "\n";


    string adventurerName ;
    while (adventurerName != "John") {
        cout << "What is your name ? It's John by the way \n";
        cin >> adventurerName;
    }

    cout << "Nice to meet you " << adventurerName << "\n";*/
   // cout << "!\nLet's check see if you're strong\n";
   // int strengthDice = (std::rand() % 6) + 1;
   // cout << "You have a strength of " << strengthDice << " ! Impressive\n ";
   // cout << "Let's check your equipment \n";

  
   //std:: vector<string> inventory = { "an axe", "an apple", "a book"};
   //for (string item : inventory) 
   //{
   //      if (item == "") { continue; }
   //      cout << "you have " << item << " and ";
   //    
   //}
   // cout << "You have " << inventory[0] << " and " << inventory[1] << "\n There is something at the bottom \n";
   // inventory.push_back("book"); 
   // cout << "It was a " << inventory[inventory.size() - 1] << "! \n";

   // map<string, int>  abilities{
   // {"Bonk Power", rand() %6 +1},
   // {"Brain Power",  rand() % 6 + 1 },
   // {"Buy Power",  rand() % 6 + 1 },
   // {"Burn Power",  rand() % 6 + 1 }
   // };

   // for (std :: pair<const string, int>& ability : abilities)
   // { 
   //     cout << "Your " << ability.first << " is : " << ability.second << "\n";
   // }
    
    //cout << "What will you become ?" << "\n 1 - A Warrior \n 2 - A Chiropractor \n 3 - L'ELECTRICIEN \n 4 - I do not want to be perceived \n";
    //int choice = 0;
   
    //do {
    //     cin >> choice;
    //    switch (choice)
    //    {
    //    case 1:
    //        cout << "Good, fight away !";
    //        break;
    //    case 2:
    //        cout << "Good, I was feeling tense";
    //        break;
    //    case 3:
    //        cout << "No";
    //        break;
    //    case 4:
    //        for (int i = 0; i < 100; i++)
    //        {
    //            cout << "Yesterday inside the code I met a man who was alone\n";
    //        }
    //        break;
    //    default:
    //        cout << "Try again PUNK \n";
    //        choice = 0;
    //    }
    //} while (choice == 0);

  
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
