// BasicCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "BodyPart.h"
#include "Poison.h"
#include "Enum.h"
#include "Inventory.h"

using std::cout;
using std::cin;
using std::string;
using std::map;
using std::vector;



#pragma region fonctions

void lineBreak() { cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n"; } 

int weaken() //Tu augmentes tes chances d'empoisoner la cible avec succès.
{
    return  rand() % 20 + 3;
}

int partSelection(vector<BodyPart> body)
{
    bool choiceIsValid = false;
    int choice = -5;
    int option = 1;
    while (choiceIsValid == false) {
        for (BodyPart part : body)
        {
            cout << "\n" << option << " - " << part.mName << "\n";
            option++;
        }
        cin >> choice;
        if (choice - 1 <= body.size() && choice >= 0) { return choice - 1; }
    }
}
#pragma endregion

int main()
{
#pragma region MAIN PROJECT
    srand(time(NULL));
   
   
    int playerLife = 50;
    int choice = 0; //La variable utilisé pour naviguer le switch
    int dodgeChance = 50; //La chance d'éviter les attaques de l'ennemi
   

    //CLASS OBJECT
    Inventory inventory;
    BodyPart leftArm("left arm", 75,5,3,75);
    BodyPart rightArm("right arm", 75, 5, 3, 75);
    Poison basePoison("Poison Basique", 1, 100,10, "None");
    Poison paralysingPoison("Poison Paralysant", 0, 75,10, "Paralysis");
    Items apple("apple", 10);
    Items wrong("wrong", 10);
    vector<BodyPart> body{ leftArm, rightArm };
    int partSelected;
    

    inventory.mItems.push_back(apple);
    inventory.mItems.push_back(wrong);
    inventory.mItems.push_back(basePoison);
    inventory.mItems.push_back(paralysingPoison);
    Poison poisonSelect[]{ basePoison };

    cout << "You're a peaceful plague doctor on a path to the woods when you encounter a wolf, you must fight ";
    lineBreak();
    
    while (leftArm.mLife > 0 && playerLife > 0) //Tant que l'un de vous est vivant
    {
    #pragma region turnStart 
        for (BodyPart part : body)
        {
            if (part.mIsPoisoned) { part.mLife -= part.poisonStatus(poisonSelect[0]); }
        }
        cout << "You have " << playerLife << " life remaining\n";
        cout << "Your poison has a potency of " << poisonSelect[0].mPoisonDamage << "\n";
        lineBreak();
#pragma endregion
#pragma region yourTurn
        dodgeChance = 0;
       
        do {
            lineBreak();
            cout << "What will you do ?\n1 - Attempt to poison one of the beast's part\n2 - Lower one of the beast's part resistance ?\n3 - Increase your poison's potency ? \n";
            cout << "4 - Dodge ?\n5 - Check a part's status\n6 - Change Poison\n";
            cin >> choice;
            system("cls");
            switch (choice) //Le switch qui détermine ce que tu fais pendant ton tour
            {
            case 1:
                lineBreak();
                partSelected = partSelection(body);
                system("cls");
                body[partSelected].mLife -= body[partSelected].poisonStatus(poisonSelect[0]);
              
                cout << "\n";
                break;
            case 2:
               lineBreak();
               cout<<"You increase the chance of your poison taking hold\n";
               partSelected = partSelection(body);
               body[partSelected].mPoisonResistance -= weaken();
               system("cls");
               cout << "\n";
               break;
            case 3:
                lineBreak();
                poisonSelect[0].mPoisonDamage++;
                cout << "Your poison will kill the beast faster !\n";
                break;
            case 4:
                lineBreak();
                dodgeChance += 50;
                cout << "You decrease the chance of the beast striking you\n";
                break;
            case 5:
                lineBreak();
                partSelected = partSelection(body);
                system("cls");
                body[partSelected].displayInfo(dodgeChance);
                choice = 0;
                break;

            case 6:
                lineBreak();
                inventory.changePoison();
                choice = 0;

            default :
                choice = 0;
            }
        } while (choice == 0);
#pragma endregion   
#pragma region enemyTurn
        
        for (BodyPart part : body)
        {
            if (part.mLife <= 0) { part.mCanPlay = false; }
            if (part.mCanPlay) { playerLife -= part.attackBasic(dodgeChance); }
        }
#pragma endregion
        
        lineBreak();
    }

    if (leftArm.mLife <= 0) { cout << "You're victorious !"; }
    else if (playerLife <= 0) { cout << "Oupsy, you died"; }

#pragma endregion


            
        
   


#pragma region Exercices
// EXERCISES

 /*switch (MyEnum::Two)
            {
            case MyEnum::One:
                cout << "Good, fight away !";
                break;
            case MyEnum::Two:
                cout << "Good, I was feeling tense";
                break;
            case MyEnum::Three:
                cout << "No";
                break;
            case MyEnum::Four:
                for (int i = 0; i < 100; i++)
                {
                    cout << "Yesterday inside the code I met a man who was alone\n";
                }
                break;
            default:
                cout << "Try again PUNK \n";  
            }*/
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

#pragma endregion
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
