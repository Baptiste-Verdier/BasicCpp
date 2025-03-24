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
void lineBreak() { cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n"; }

int attackBasic() 
{
    return (rand() % 3) + 1;
}

bool isPoisoned(int poisonChance)
{
    if ((rand()%100)+1 <= poisonChance)
        {
            return true;
        } 
    else {return false;} 
}
int main()
{
    srand(time(NULL));
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

    int poisonChance = 0;
    int playerLife = 25;
    int wolfLife = 25;

    cout << "You're a peaceful plague doctor on a path to the woods when you encounter a wolf, you must fight ";
    lineBreak();
    while (wolfLife >= 0 || playerLife >= 0) 
    {
        cout << "You have " << playerLife << " life remaining\n";
        cout << "The wolf has " << wolfLife << " life remaining\n";

        playerLife -= attackBasic();
        wolfLife -= attackBasic();

        lineBreak();
    }
    if (wolfLife <= 0) { cout << "You're victorious !"; }
    else if (playerLife <= 0) { cout << "Oupsy, you died"; }

    return 0;
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
