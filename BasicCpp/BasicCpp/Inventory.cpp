#include "Inventory.h"
#include "Items.h"
#include "Poison.h"
#include <iostream>

#include <vector>
using std::vector;

using std::cout;

Inventory::Inventory():
	mItems{ mPoison}
{ }

void Inventory::changePoison()const  

{
	int option = 1;
		

		
	for ( Items item : mItems ) // Je consid�re la variable poison d�clar� ici, mItems est un vecteur d'Items
	{
		Items* pItem = &item;
		

		Poison* pIsPoison = dynamic_cast<Poison*>(pItem);
		

		//if (pIsPoison) //Je verifie si l'Item est de type Poison
		//{
		//	cout << option << " - " << item.mName << "\n";
		//	option++;
		//}
		/*else { cout << pIsPoison << "\n"; }*/
	}
}