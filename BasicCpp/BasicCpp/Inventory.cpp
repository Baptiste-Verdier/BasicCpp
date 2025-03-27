#include "Inventory.h"
#include "Items.h"
#include "Poison.h"
#include <iostream>

#include <vector>
using std::vector;

using std::cout;

Inventory::Inventory():
	mItems{ mPoison},
	mItemsPtr{ &mItems },
	mMoney{ 0 }
{ }

void Inventory::changePoison()const  

{
	int option = 1;
	for ( Items& item : *mItemsPtr ) 
	{
		Items* pItem = &item;
		Poison* pPoison = dynamic_cast<Poison*>(pItem);

		if (pPoison)
		{
			Items poison = *pItem;
			cout << option << " - "; 
			poison.GetName();
			option++;
		}
		else { cout << pPoison << "\n"; }
	}
}