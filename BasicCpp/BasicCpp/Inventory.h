#pragma once
#include "Items.h"
#include <vector>
#include "Poison.h"

using std::vector;


class Inventory
{
public:
	Inventory();
	int mMoney;
	Items selected[1];
	Poison* changePoison() const;
	void buy(Items bought) const;
	vector<Items*> mItems;
	
private: 
	Items mPoison;
};