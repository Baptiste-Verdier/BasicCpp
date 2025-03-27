#pragma once
#include "Items.h"
#include <vector>

using std::vector;


class Inventory
{
public:
	Inventory();
	int mMoney;
	vector <Items> mItems;
	Items selected[1];
	void changePoison() const;
	void buy(Items bought) const;
	vector<Items>* mItemsPtr;
	
private: 
	Items mPoison;
};