#include "Inventory.h"
#include "Items.h"
#include <iostream>

#include <vector>
using std::vector;
using std::cout;
using std::cin;

Inventory::Inventory():
	mItems{ },
	mMoney{ 0 }
{ }

Poison* Inventory::changePoison() const
{
	bool isChoiceValid = false;
	int option = 1;
	int choice = 0;
	vector<Poison*> poisonOptions;
	for ( Items* item : mItems ) 
	{
		if (Poison* pPoison = dynamic_cast<Poison*>(item))
		{
			poisonOptions.push_back(pPoison);
			cout << option << " - "; 
			pPoison->GetName();
			option++;
			
		}
	}
	while (isChoiceValid == false)
	{
		cin >> choice;
		if (choice - 1 <= poisonOptions.size() && choice - 1 >= 0) { return poisonOptions[choice - 1]; }
		return poisonOptions[0];
	}
}