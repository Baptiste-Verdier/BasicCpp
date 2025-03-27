#pragma once
#include <string>
using std :: string;
class Items
{
public :
	Items();
	Items(string name, int price);
	virtual ~Items();
	void GetName() const;
	void GetPrice() const;

protected :
	int const mPrice;
	string mName;
};

