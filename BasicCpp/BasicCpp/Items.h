#pragma once
#include <string>
using std :: string;
class Items
{
public :
	Items();
	Items(string name, int price);
	string mName;

private :
	int const mPrice;
};

